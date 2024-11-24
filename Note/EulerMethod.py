import math
import re


class EulerMethod:
    input_equation: str = ""
    x_first: float = 0
    y_first: float = 0
    y_prev: float = 0
    end: float = 0
    h: float = 0

    @staticmethod
    def to_float(s) -> float:  # this function saved me
        if s == "+" or len(s) == 0:
            return 1
        elif s == "-":
            return -1
        else:
            return float(s)

    def find_div_sign_position(self) -> int:
        return self.input_equation.find('/')  # this is a lame logic,
        # I need to use stack based implementation for parenthesis

    def take_input(self) -> None:
        print("Please enter the equation: dy/dx : ")
        self.input_equation = input()
        self.input_equation = self.input_equation.replace(" ", "")
        self.h = float(input("input h : "))
        self.x_first = float(input("input x_first = "))
        self.y_first = float(input("input y_first = "))
        self.end = float(input("input end : "))

    def print_input_equation(self) -> None:
        print(self.input_equation)

    def _f_half(self, v, str_main) -> float:
        result = 0
        str = str_main
        # ==============================================================================
        # PROCESS TRIGONOMETRY
        regex = re.compile(r"[+-]?\d*(?:sin|cos|tan)\([+-]?\d*x?[+-]?\d*\)")
        all_trigonometry = re.findall(regex, str)
        # print(all_e_pow_x)
        for p in all_trigonometry:
            # print('\n', p)
            regex_value1 = re.findall(re.compile(r"[+-]?\d*(?:sin|cos|tan)"), p)
            # print("regex_value1 = ", regex_value1)
            trig_func_name = regex_value1[0][-3:]
            # print("trig_func_name = ", trig_func_name)
            regex_value1[0] = re.sub(r'sin|cos|tan', '', regex_value1[0])
            coeff_t = 1 if not regex_value1 else self.to_float(regex_value1[0][:])
            # print("coeff_t = ", coeff_t)

            regex_value2 = re.findall(re.compile(r"\([+-]?\d*x"), p)
            # print("regex_value2 = ", regex_value2)
            if regex_value2:
                regex_value2[0] = re.sub(r'x', '', regex_value2[0])
                regex_value2[0] = re.sub(r'\(', '', regex_value2[0])
            # print("regex_value2 = ", regex_value2)
            coeff_x = 0 if not regex_value2 else self.to_float(regex_value2[0][:])
            # print("coeff_x = ", coeff_x)

            regex_value3 = re.findall(re.compile(r"[+-]?\d*\)"), p)
            # print("regex_value3 = ", regex_value3)
            if regex_value3:
                regex_value3[0] = re.sub(r'\)', '', regex_value3[0])
            # print("regex_value3 = ", regex_value3)
            const_ = 0 if regex_value3[0] == '' else self.to_float(regex_value3[0][:])
            # print("const_ = ", const_)
            val_for_eval = (coeff_x * v) + const_
            # print("val_for_eval = ", val_for_eval)

            if trig_func_name == 'sin':
                val_for_eval = math.sin(val_for_eval)
            elif trig_func_name == "cos":
                val_for_eval = math.cos(val_for_eval)
            elif trig_func_name == "tan":
                val_for_eval = math.tan(val_for_eval)

            result += (coeff_t * val_for_eval)
            str = str.replace(p, "")
        # end for
        # ==============================================================================
        # PROCESS E^x
        regex_e_pow_x = re.compile(r"[+-]?\d*\.?\d?e\^[+-]?\d*\.?\d?x")
        all_e_pow_x = re.findall(regex_e_pow_x, str)
        # print(all_e_pow_x)
        for p in all_e_pow_x:
            # print('\n')
            coeff_str = re.findall(re.compile(r"[+-]?\d*\.?\d?e"), p)
            # print("coeff_str = ", coeff_str[0])
            coeff = self.to_float(coeff_str[0][:-1])
            # print("coeff = ", coeff)

            pow_str = re.findall(re.compile(r"[+-]?\d*\.?\d?x"), p)
            # print("pow_str = ", pow_str[0])
            pow = self.to_float(pow_str[0][:-1])
            # print("pow = ", pow)
            result += coeff * math.exp(pow * v)
            str = str.replace(p, '')
        # end for
        # ==============================================================================
        # PROCESS XY
        regex_xy = re.compile(r"[+-]?\d*\.?\d?(?:xy|yx)")
        all_xy = re.findall(regex_xy, str)
        for p in all_xy:
            regex_value1 = p[0:-2]
            print("xy = ", regex_value1, " ", self.to_float(regex_value1))
            result += self.to_float(regex_value1) * v * self.y_prev
            str = str.replace(p, '')
        # end for
        # ==============================================================================
        # PROCESS Y
        # first, process multiple powers of y, then remove those multiple power terms
        regex_polynomials_of_y = re.compile(r"[+-]?\d*y(?:\^[+-]?\d*)")
        polynomials_multi = re.findall(regex_polynomials_of_y, str)

        for p in polynomials_multi:
            regex_value1 = re.findall(re.compile(r"[+-]?\d*y"), p)
            # print("regex_value1 = ", regex_value1)
            coeff = 1 if not regex_value1 else self.to_float(regex_value1[0][:-1])
            # print("coeff = ", coeff)

            regex_value2 = re.findall(re.compile(r"y\^+[+-]?\d*"), p)
            # print("regex_value2 = ", regex_value2)
            pow = 1 if not regex_value2 else self.to_float(regex_value2[0][2:])
            # print("pow = ", pow)
            result += coeff * math.pow(self.y_prev, pow)
            str = str.replace(p, "")
        # end for

        # Process edge case,,,
        regex_y_to_the_pow_one = re.compile(r"[+-]?\d*y")
        polynomials_one = re.findall(regex_y_to_the_pow_one, str)

        for p in polynomials_one:
            regex_value1 = re.findall(re.compile(r"[+-]?\d*y"), p)
            # print("regex_value1 = ", regex_value1)
            coeff = 1 if not regex_value1 else self.to_float(regex_value1[0][:-1])
            # print("coeff = ", coeff)
            result += coeff * self.y_prev
            str = str.replace(p, "")
        # end for
        # PROCESS Y END
        # ==============================================================================
        # PROCESS X
        # first, process multiple powers of x, then remove those multiple power terms
        regex_polynomials_of_x = re.compile(r"[+-]?\d*x(?:\^[+-]?\d*)")
        polynomials_multi = re.findall(regex_polynomials_of_x, str)

        for p in polynomials_multi:
            # print("\n", p)

            regex_value1 = re.findall(re.compile(r"[+-]?\d*x"), p)
            # print("regex_value1 = ", regex_value1)
            coeff = 1 if not regex_value1 else self.to_float(regex_value1[0][:-1])
            # print("coeff = ", coeff)

            regex_value2 = re.findall(re.compile(r"x\^+[+-]?\d*"), p)
            # print("regex_value2 = ", regex_value2)
            pow = 1 if not regex_value2 else self.to_float(regex_value2[0][2:])
            # print("pow = ", pow)
            result += coeff * math.pow(v, pow)
            str = str.replace(p, "")
        # end for

        # Process edge case,,,
        regex_x_to_the_pow_one = re.compile(r"[+-]?\d*x")
        polynomials_one = re.findall(regex_x_to_the_pow_one, str)
        # print(polynomials_one)
        for p in polynomials_one:
            # print("\n", p)
            regex_value1 = re.findall(re.compile(r"[+-]?\d*x"), p)
            # print("regex_value1 = ", regex_value1")
            coeff = 1 if not regex_value1 else self.to_float(regex_value1[0][:-1])
            # print("coeff = ", coeff)")
            result += coeff * v
            str = str.replace(p, "")
        # end for
        # END PROCESS X
        # ==============================================================================
        # result += self.to_float(str)
        result += eval(str)
        return result

    def f(self, v):
        div_sign_position = self.find_div_sign_position()
        if div_sign_position != -1:
            numerator: float = self._f_half(v, self.input_equation[0, div_sign_position])
            denominator: float = self._f_half(v, self.input_equation[div_sign_position + 1, len(self.input_equation)])
            if denominator == 0:
                denominator = 1
            return numerator / denominator
        else:
            return self._f_half(v, self.input_equation)

    def perform_euler_method(self) -> None:
        i: float = 1.0
        # for i in range(self.x_first, self.end + self.h, self.h):
        while i <= self.end:
            if i == 1:
                self.y_prev = self.y_first
                print(r"y(", i, ") = ", self.y_prev)
                i += self.h
                continue

            y_new = self.y_prev + self.h * self.f(i - self.h)
            print("y(", i, ") = ", y_new)
            self.y_prev = y_new
            i += self.h
        # while loop end


if __name__ == "__main__":
    eulerMethod = EulerMethod()
    eulerMethod.take_input()
    eulerMethod.perform_euler_method()
