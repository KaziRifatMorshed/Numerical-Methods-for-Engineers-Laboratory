import math
import re


# NOTE: processing priority: sin, cos, tan, e^x, xy, y, x, coefficient

def to_float(s) -> float:  # this function saved me
    if s == "+" or len(s) == 0:
        return 1
    elif s == "-":
        return -1
    else:
        return float(s)


str_main = ""
print('\n')

# EVALUATE STARTS
str_main = str_main.replace(" ", "")
str = str_main
x = 1
y_prev = 0
result = 0

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
    coeff_t = 1 if not regex_value1 else to_float(regex_value1[0][:])
    # print("coeff_t = ", coeff_t)

    regex_value2 = re.findall(re.compile(r"\([+-]?\d*x"), p)
    # print("regex_value2 = ", regex_value2)
    if regex_value2:
        regex_value2[0] = re.sub(r'x', '', regex_value2[0])
        regex_value2[0] = re.sub(r'\(', '', regex_value2[0])
    # print("regex_value2 = ", regex_value2)
    coeff_x = 0 if not regex_value2 else to_float(regex_value2[0][:])
    # print("coeff_x = ", coeff_x)

    regex_value3 = re.findall(re.compile(r"[+-]?\d*\)"), p)
    # print("regex_value3 = ", regex_value3)
    if regex_value3:
        regex_value3[0] = re.sub(r'\)', '', regex_value3[0])
    # print("regex_value3 = ", regex_value3)
    const_ = 0 if regex_value3[0] == '' else to_float(regex_value3[0][:])
    # print("const_ = ", const_)
    val_for_eval = coeff_x * x + const_
    # print("val_for_eval = ", val_for_eval)

    if trig_func_name == "sin":
        val_for_eval = math.sin(val_for_eval)
    elif trig_func_name == "cos":
        val_for_eval = math.cos(val_for_eval)
    elif trig_func_name == "tan":
        val_for_eval = math.tan(val_for_eval)

    result += coeff_t * val_for_eval
    str_n = str_n.replace(p, "")

# ==============================================================================

# PROCESS E^x

regex_e_pow_x = re.compile(r"[+-]?\d*\.?\d?e\^[+-]?\d*\.?\d?x")
all_e_pow_x = re.findall(regex_e_pow_x, str_n)
# print(all_e_pow_x)

for p in all_e_pow_x:
    print('\n')
    coeff_str = re.findall(re.compile(r"[+-]?\d*\.?\d?e"), p)
    print("coeff_str = ", coeff_str[0])
    coeff = to_float(coeff_str[0][:-1])
    print("coeff = ", coeff)

    pow_str = re.findall(re.compile(r"[+-]?\d*\.?\d?x"), p)
    print("pow_str = ", pow_str[0])
    pow = to_float(pow_str[0][:-1])
    print("pow = ", pow)
    result += coeff * math.exp(pow * x)
    str = str.replace(p, '')
# ==============================================================================

# PROCESS XY

regex_xy = re.compile(r"[+-]?\d*\.?\d?(?:xy|yx)")
all_xy = re.findall(regex_xy, str)
for p in all_xy:
    regex_value1 = p[0:-2]
    print("xy = ", regex_value1, " ", to_float(regex_value1))
    result += to_float(regex_value1)
    str = str.replace(p, '')

# ==============================================================================

# PROCESS Y

# print("str = ", str)
# first, process multiple powers of y, then remove those multiple power terms
regex_polynomials_of_y = re.compile(r"[+-]?\d*y(?:\^[+-]?\d*)")
polynomials_multi = re.findall(regex_polynomials_of_y, str)

print("polynomials_multi = ", polynomials_multi)

for p in polynomials_multi:
    regex_value1 = re.findall(re.compile(r"[+-]?\d*y"), p)
    # print("regex_value1 = ", regex_value1)
    coeff = 1 if not regex_value1 else to_float(regex_value1[0][:-1])
    # print("coeff = ", coeff)

    regex_value2 = re.findall(re.compile(r"y\^+[+-]?\d*"), p)
    # print("regex_value2 = ", regex_value2)
    pow = 1 if not regex_value2 else to_float(regex_value2[0][2:])
    # print("pow = ", pow)
    result += coeff * math.pow(y_prev, pow)
    str = str.replace(p, "")
# end for
# print("str = ", str)

# Process edge case,,,
regex_y_to_the_pow_one = re.compile(r"[+-]?\d*y")
polynomials_one = re.findall(regex_y_to_the_pow_one, str)

print(polynomials_one)

for p in polynomials_one:
    regex_value1 = re.findall(re.compile(r"[+-]?\d*y"), p)
    print("regex_value1 = ", regex_value1)
    coeff = 1 if not regex_value1 else to_float(regex_value1[0][:-1])
    print("coeff = ", coeff)
    result += coeff * y_prev
    str = str.replace(p, "")
# end for
print(str)

print("\nresult = ", result)
# PROCESS Y END

# ==============================================================================

# PROCESS X
# str = str_main
print("str = ", str)
# first, process multiple powers of x, then remove those multiple power terms
regex_polynomials_of_x = re.compile(r"[+-]?\d*x(?:\^[+-]?\d*)")
polynomials_multi = re.findall(regex_polynomials_of_x, str)

print(polynomials_multi)

for p in polynomials_multi:
    # print("\n", p)

    regex_value1 = re.findall(re.compile(r"[+-]?\d*x"), p)
    # print("regex_value1 = ", regex_value1)
    coeff = 1 if not regex_value1 else to_float(regex_value1[0][:-1])
    # print("coeff = ", coeff)

    regex_value2 = re.findall(re.compile(r"x\^+[+-]?\d*"), p)
    # print("regex_value2 = ", regex_value2)
    pow = 1 if not regex_value2 else to_float(regex_value2[0][2:])
    # print("pow = ", pow)
    result += coeff * math.pow(x, pow)
    str = str.replace(p, "")
# end for

# Process edge case,,,
regex_x_to_the_pow_one = re.compile(r"[+-]?\d*x")
polynomials_one = re.findall(regex_x_to_the_pow_one, str)

# print(polynomials_one)

for p in polynomials_one:
    # print("\n", p)

    regex_value1 = re.findall(re.compile(r"[+-]?\d*x"), p)
    # print("regex_value1 = ", regex_value1)
    coeff = 1 if not regex_value1 else to_float(regex_value1[0][:-1])
    # print("coeff = ", coeff)
    result += coeff * x
    str = str.replace(p, "")
# end for
# print(str)

# END PROCESS X

# ==============================================================================


# rest are for rest

# regex = re.compile(r"[+-]?\d*e\^\d*x")
# result2 = re.findall(regex, str)
# print(result2)
#
# regex = re.compile(r"[+-]?\d*sin\(\d*x[+-]?\d*\)")
# result2 = re.findall(regex, str)
# print(result2)
#
# # constant ??????????/
# regex = re.compile(r"[+-]?\d*")
# result2 = re.findall(regex, str)
# print(result2)
