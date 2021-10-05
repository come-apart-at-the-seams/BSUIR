import matplotlib.pyplot as plt
import math

# Эмпирическая функция распределения
def empir(Y, n, needPrint):
    Y.sort()
    i = 0
    Fn = [0]
    while i <= n:
        fn = i / n
        Fn.append(fn)
        i += 1
    Fn.append(1)

    yyy = [Y[0]-1] + [Y[0]] + Y + [Y[-1] + 1]
    if needPrint:
        print("\n\t\t\t\tЭмпирическая функция распределения:\n")
        for i in range(n + 3):
            print(f"y = {yyy[i]}, \t Fn = {Fn[i]}")

    plt.step(yyy, Fn, 'b', where='post')
    plt.show()

def empir2(Y, m, n):
    Y.sort()
    Fn = [0]
    sum = 0
    for mi in m:
        sum += mi
        fn = sum / n
        Fn.append(fn)
    Fn.append(1)

    yyy = [Y[0]-1] + Y + [Y[-1] + 1]

    print(len(Fn))
    print(len(yyy))
    plt.step(yyy, Fn, 'b', where='post')
    plt.show()

def teorAndEmpir(Y, n):
    Y.sort()
    i = 0
    Fn = [0]
    while i <= n:
        fn = i / n
        Fn.append(fn)
        i += 1
    Fn.append(1)

    yyy = [Y[0]-1] + [Y[0]] + Y + [Y[-1] + 1]

    plt.step(yyy, Fn, 'b', where='post')

    fx = []
    x = []
    for i in range(0, 40000, 1):
        x.append(i/10000)
        fx.append(math.sqrt(x[i])*0.5)
    plt.plot(x, fx, 'red')

    plt.show()

def densityWitoutPlot():
    x =[]
    y =[]
    for i in range(1,4000, 1):
        x.append(i/1000)
        y.append(1/(4*math.sqrt(x[i-1])))
    return x, y