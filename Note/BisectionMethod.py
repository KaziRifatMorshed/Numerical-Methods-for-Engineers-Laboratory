def f(x: float, a: float, b: float, c: float) -> float:
    return (a * x * x) + (b * x) + c


def main():
    a, b, c = map(float, input("Please input a, b, c (with spaces) : ").split())
    x1, x2 = map(float, input("Please input x1, x2 (with spaces) : ").split())
    n = int(input("Please input iteration limit [input 0 if you do not want to specify this limit] : "))
    i: int = 1
    
    while (i <= n) or (n == 0):
        x0: float = (x1 + x2) / 2
        f_x0: float = f(x0, a, b, c)
        print("Iteration no : ", i, "\tx0 = ", x0, "\t\tf(x0) = ", f_x0)

        if abs(f_x0) < 0.000005:
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
Please input a, b, c (with spaces) : 1 -4 -10
Please input x1, x2 (with spaces) : -2 -1
Please input iteration limit [input 0 if you do not want to specify this limit] : 30
Iteration no :  1 	x0 =  -1.5 		f_x0 =  -1.75
Iteration no :  2 	x0 =  -1.75 		f_x0 =  0.0625
Iteration no :  3 	x0 =  -1.625 		f_x0 =  -0.859375
Iteration no :  4 	x0 =  -1.6875 		f_x0 =  -0.40234375
Iteration no :  5 	x0 =  -1.71875 		f_x0 =  -0.1708984375
Iteration no :  6 	x0 =  -1.734375 		f_x0 =  -0.054443359375
Iteration no :  7 	x0 =  -1.7421875 		f_x0 =  0.00396728515625
Root Found
Root is appx  -1.7421875
Program Completed
"""

"""
Please input a, b, c (with spaces) : 1 1 -2
Please input x1, x2 (with spaces) : .5 2
Please input iteration limit [input 0 if you do not want to specify this limit] : 30
Iteration no :  1 	x0 =  1.25 		f_x0 =  0.8125
Iteration no :  2 	x0 =  0.875 		f_x0 =  -0.359375
Iteration no :  3 	x0 =  1.0625 		f_x0 =  0.19140625
Iteration no :  4 	x0 =  0.96875 		f_x0 =  -0.0927734375
Iteration no :  5 	x0 =  1.015625 		f_x0 =  0.047119140625
Iteration no :  6 	x0 =  0.9921875 		f_x0 =  -0.02337646484375
Iteration no :  7 	x0 =  1.00390625 		f_x0 =  0.0117340087890625
Iteration no :  8 	x0 =  0.998046875 		f_x0 =  -0.005855560302734375
Iteration no :  9 	x0 =  1.0009765625 		f_x0 =  0.0029306411743164062
Root Found
Root is appx  1.0009765625
Program Completed


Please input a, b, c (with spaces) : 1 1 -2
Please input x1, x2 (with spaces) : 0.5 2
Please input iteration limit [input 0 if you do not want to specify this limit] : 30
Iteration no :  1 	x0 =  1.25 		f(x0) =  0.8125
Iteration no :  2 	x0 =  0.875 		f(x0) =  -0.359375
Iteration no :  3 	x0 =  1.0625 		f(x0) =  0.19140625
Iteration no :  4 	x0 =  0.96875 		f(x0) =  -0.0927734375
Iteration no :  5 	x0 =  1.015625 		f(x0) =  0.047119140625
Iteration no :  6 	x0 =  0.9921875 		f(x0) =  -0.02337646484375
Iteration no :  7 	x0 =  1.00390625 		f(x0) =  0.0117340087890625
Iteration no :  8 	x0 =  0.998046875 		f(x0) =  -0.005855560302734375
Iteration no :  9 	x0 =  1.0009765625 		f(x0) =  0.0029306411743164062
Iteration no :  10 	x0 =  0.99951171875 		f(x0) =  -0.0014646053314208984
Iteration no :  11 	x0 =  1.000244140625 		f(x0) =  0.0007324814796447754
Iteration no :  12 	x0 =  0.9998779296875 		f(x0) =  -0.00036619603633880615
Root Found
Root is appx  0.9998779296875
Program Completed


Please input a, b, c (with spaces) : 1 1 -2
Please input x1, x2 (with spaces) : 0.5 2
Please input iteration limit [input 0 if you do not want to specify this limit] : 0
Iteration no :  1 	x0 =  1.25 		f(x0) =  0.8125
Iteration no :  2 	x0 =  0.875 		f(x0) =  -0.359375
Iteration no :  3 	x0 =  1.0625 		f(x0) =  0.19140625
Iteration no :  4 	x0 =  0.96875 		f(x0) =  -0.0927734375
Iteration no :  5 	x0 =  1.015625 		f(x0) =  0.047119140625
Iteration no :  6 	x0 =  0.9921875 		f(x0) =  -0.02337646484375
Iteration no :  7 	x0 =  1.00390625 		f(x0) =  0.0117340087890625
Iteration no :  8 	x0 =  0.998046875 		f(x0) =  -0.005855560302734375
Iteration no :  9 	x0 =  1.0009765625 		f(x0) =  0.0029306411743164062
Iteration no :  10 	x0 =  0.99951171875 		f(x0) =  -0.0014646053314208984
Iteration no :  11 	x0 =  1.000244140625 		f(x0) =  0.0007324814796447754
Iteration no :  12 	x0 =  0.9998779296875 		f(x0) =  -0.00036619603633880615
Iteration no :  13 	x0 =  1.00006103515625 		f(x0) =  0.00018310919404029846
Iteration no :  14 	x0 =  0.999969482421875 		f(x0) =  -9.155180305242538e-05
Iteration no :  15 	x0 =  1.0000152587890625 		f(x0) =  4.5776600018143654e-05
Iteration no :  16 	x0 =  0.9999923706054688 		f(x0) =  -2.2888125386089087e-05
Iteration no :  17 	x0 =  1.0000038146972656 		f(x0) =  1.1444106348790228e-05
Iteration no :  18 	x0 =  0.9999980926513672 		f(x0) =  -5.722042260458693e-06
Iteration no :  19 	x0 =  1.0000009536743164 		f(x0) =  2.8610238587134518e-06
Root Found
Root is appx  1.0000009536743164
Program Completed
"""