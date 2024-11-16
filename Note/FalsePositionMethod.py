def f(x: float, a: float, b: float, c: float) -> float:
    return (a * x * x) + c + (b * x)


def main():
    a, b, c = map(float, input("Please input a, b, c (with spaces) : ").split())
    x1, x2 = map(float, input("Please input x1, x2 (with spaces) : ").split())
    n = int(input("Please input iteration limit [input 0 if you do not want to specify this limit] : "))
    i: int = 1
    while i <= n or i == 0:
        x0: float = x1 - ((f(x1, a, b, c) * (x2 - x1)) / (f(x2, a, b, c) - f(x1, a, b, c)))
        f_x0: float = f(x0, a, b, c)
        print("Iteration no : ", i, "\tx0 = ", x0, "\t\tf_x0 = ", f_x0)

        if abs(f_x0) < 0.005:
            print("Root Found\nRoot is appx ", x0)
            break
        elif (f_x0 * f(x1, a, b, c)) < 0:
            x2 = x0
        elif (f_x0 * f(x2, a, b, c)) < 0:
            x1 = x0
        i = i + 1

    print("Program Completed")


if __name__ == '__main__':
    main()

"""
/usr/bin/python3.12 /home/scr33nw0rm/Documents/GitHub/LearningPython/NumericalMethods/FalsePositionMethod.py 
Please input a, b, c (with spaces) : 1 -4 -10
Please input x1, x2 (with spaces) : -2 -1
Please input iteration limit [input 0 if you do not want to specify this limit] : 30
Iteration no :  1 	x0 =  -1.7142857142857144 		f_x0 =  -0.20408163265306012
Iteration no :  2 	x0 =  -1.7407407407407407 		f_x0 =  -0.006858710562414494
Iteration no :  3 	x0 =  -1.7416267942583732 		f_x0 =  -0.00022893248780953002
Root Found
Root is appx  -1.7416267942583732
Program Completed
"""