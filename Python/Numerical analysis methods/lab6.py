import numpy as np
import matplotlib.pyplot as plt

x = np.array([2, 5, -6, 7, 4, 3, 8, 9, 1, -2], dtype=float)
y = np.array([-1, 77, -297, 249, 33, 9, 389, 573, -3, -21], dtype=float)
# x = np.array([1, 0, -2.5], dtype=float)
# y = np.array([0, -6, -12.25], dtype=float)


def lagranz (x, y, t):
    z = 0
    for j in range(len(y)):
        p1 = 1
        p2 = 1
        for i in range(len(x)):
            if i == j:
                p1 = p1 * 1
                p2 = p2 * 1
            else:
                p1 = p1 * (t - x[i])
                p2 = p2 * (x[j] - x[i])
            # print('p1 = ', p1)
            # print('p2 = ', p2)
        z = z + y[j] * p1 / p2
    return z

import mpmath
from sympy import *

def lagranz20 (x, y):
    z = 0
    X = symbols('x')
    for j in range(len(y)):
        p1 = 1
        p2 = 1
        for i in range(len(x)):
            if i == j:
                p1 = p1 * 1
                p2 = p2 * 1
            else:
                p1 = p1 * (X - x[i])
                p2 = p2 * (x[j] - x[i])
        z = z + y[j] * p1 / p2
    return z


oversize = 10
xnew = np.linspace(np.min(x - oversize), np.max(x + oversize), 10)
ynew = [lagranz(x, y, i) for i in xnew]
plt.plot(x, y, 'o', xnew, ynew)
plt.grid(True)
plt.show()
print('lagranz')
print(simplify(lagranz20(x, y)))

# todo


import numpy as np


# import matplotlib.pyplot as plt

def coef (x, y):
    '''x : array of data points
       y : array of f(x)  '''
    x.astype(float)
    y.astype(float)
    n = len(x)
    a = []
    for i in range(n):
        a.append(y[i])

    for j in range(1, n):

        for i in range(n - 1, j - 1, -1):
            a[i] = float(a[i] - a[i - 1]) / float(x[i] - x[i - j])

    return np.array(a)  # return an array of coefficient


def Eval (a, x, r):
    # ''' a : array returned by function coef()
    #    x : array of data points
    #    r : the node to interpolate at  '''

    x.astype(float)
    n = len(a) - 1
    temp = a[n] + (r - x[n])
    for i in range(n - 1, -1, -1):
        temp = temp * (r - x[i]) + a[i]
    return temp  # return the y_value interpolation


print()
print(coef(x, y))
print(Eval(coef(x, y), x, 9))
