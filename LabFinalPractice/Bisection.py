import re


class BisectionMethod:
    x1: float = 0
    x2: float = 0
    n: float = 0
    a: float = 0
    b: float = 0
    c: float = 0
    eq: str = ""
    E: float = 0.005

    @staticmethod
    def to_float(s) -> float:
        if s == "+" or len(s) == 0:
            return 1
        elif s == "-":
            return -1
        else:
            return float(s)

    def f(self, x: float):
        return self.a * pow(x, 2) + self.b * x + self.c

    def str_to_values(self):
        regex = re.compile(r"[+-]\d*x[123]")
        results = re.findall(regex, self.eq)
        print(results)
        self.a = self.to_float(results[0])
        self.b = self.to_float(results[1])
        self.c = self.to_float(results[2])

    def take_input(self):
        self.x1 = float(input("Input x1 : "))
        self.x2 = float(input("Input x2 : "))
        self.n = float(input("Input Iteration Number, n : "))
        self.eq = input("input Equation")
        self.str_to_values()

    def solve(self):
        self.take_input()

        for i in range(1, self.n):
            x0: float = (self.x1 + self.x2) / 2
            if x0 < self.E:
                print("Result = ", x0)
                break
            elif self.f(x0) * self.f(self.x1) < 0:
                self.x2 = x0
            else:
                self.x1 = x0


# //////////////////////////////////////////////////////////////////////////////
if __name__ == "__main__":
    b_method = BisectionMethod()
    b_method.solve()
