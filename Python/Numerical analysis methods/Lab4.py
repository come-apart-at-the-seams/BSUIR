import math as m
import numpy as np


def maxMagnitudes(dX):
    d = np.abs(dX[0])
    for i in dX:
        if (np.abs(i) > d):
            d = np.abs(i)
    return d


# def invert(M):
#     N.copy(M)
#     for i in range(len(M)):
#         for j in range(len(M[0])):
#             N[i][j] = M[j][i]
#     return N

def dF(X):
    x = X[0]
    y = X[1]
    df = [[0, 0],
          [0, 0]]
    df[0][0] = (1/m.cos(x*y))**2 *y -1
    df[0][1] = (1/m.cos(x*y))**2 *x
    df[1][0] = x
    df[1][1] = 4*y
    # df[0][0] = 1 + y**3
    # df[0][1] = 3*y**2*x
    # df[1][0] = y+y**2
    # df[1][1] = x + 2*y*x
    return df

def F(X):
    x = X[0]
    y = X[1]
    f =[0, 0]
    f[0] = m.tan(x*y) - x
    f[1] = 0.5*(x**2) + 2*(y**2) - 1
    # f[0] = x + x*y**3-9
    # f[1] = x*y +x*y**2-6
    return f

def prosto(X):
    x = X[0]
    y = X[1]
    f = [0, 0]
    f[0] = m.tan(x * y)
    f[1] = m.sqrt((-0.5 * (x ** 2) + 1)/2)
    # f[0] = x + x*y**3-9
    # f[1] = x*y +x*y**2-6
    return f

X = np.array([0, 0.7])
Xlast = np.array([0, 0])
W = np.array([[1, 1],
              [1, 1]])
dX = np.array([0, 0])
Dx = 1

i = 0
while(Dx > 0.0001):
    i += 1
    Xlast = X
    W = dF(X)
    # print('F = ')
    # print(F(X))
    # print('W = ')
    # print(W)
    # print(np.linalg.inv(W))
    c = np.matmul(np.linalg.inv(W), F(Xlast))
    X = X - c.dot(0.1)

    # dX[0] = X[0] - Xlast[0]
    # dX[1] = X[1] - Xlast[1]
    dX = X - Xlast
    Dx = maxMagnitudes(dX)

    # print(Dx)
    # print(X)
    # print(m.tan(X[0] * X[1]) - X[0])
print(X)
print(i)

# print(m.tan(X[0]*X[1])-X[0])


X = np.array([1, 0.7])
Xlast = np.array([0, 0])
dX = np.array([0, 0])
Dx = 1

i = 0

while Dx > 0.0001:
    i+=1
    Xlast = X
    # print('X = ')
    # print(X)
    # print('Fx = ')
    #print(prosto(X))
    X = np.array(prosto(X))

    dX = X - Xlast
    Dx = maxMagnitudes(dX)
print('\nProsto')
print(X)
print(i)