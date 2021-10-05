import math
from numpy import array, identity, diagonal

# def jacobii(n, a, d, v):
#     #( const unsigned int n, double * const * a, double * d, double * const * v )
#     if n == 0:
#         return 0
#     b = [None] * (n + n)
#     z = [None] * (3*n)
#     for i in range(n):
#         z[i] = 0
#         b[i] = d[i] = a[i][i]
#         for j in range(n):
#             # v[i][j] = i == j ? 1. : 0.
#             if i == j:
#                 v[i][j] = 1.
#             else:
#                 v[i][j] = 0.
#     for i in range(50):
#         sm = 0.
#         for p in range(n-1):
#             for q in range(p + 1, n, 1): # ( q = p + 1; q < n; ++q )
#                 sm += abs ( a[p][q] )
#         if sm == 0:
#             break
#         # tresh = i < 3 ? 0.2 * sm / ( n*n ) : 0.
#         if i < 3:
#             tresh = 0.2 * sm / ( n*n )
#         else:
#             tresh = 0.
#         for p in range(n-1):#( p = 0; p < n - 1; ++p ):
#             for q in range(p+1, n, 1):#( q = p + 1; q < n; ++q ):
#                 g = 1e12 * abs(a[p][q])
#                 if i >= 3 and abs( d[p] ) > g and abs( d[q] ) > g :
#                     a[p][q] = 0.
#                 elif abs( a[p][q] ) > tresh:
#                     theta = 0.5 * ( d[q] - d[p] ) / a[p][q]
#                     t = 1. / ( abs(theta) + math.sqrt(1.+theta*theta) )
#                     if theta < 0:
#                         t = - t
#                     c = 1. / math.sqrt ( 1. + t*t )
#                     s = t * c
#                     tau = s / ( 1. + c )
#                     h = t * a[p][q]
#                     z[p] -= h
#                     z[q] += h
#                     d[p] -= h
#                     d[q] += h
#                     a[p][q] = 0.
#                     for j in range(p):
#
#                         g = a[j][p]
#                         h = a[j][q]
#                         a[j][p] = g - s * ( h + g * tau )
#                         a[j][q] = h + s * ( g - h * tau )
#
#                     for j in range(p+1, q, 1):#( j = p+1; j < q; ++j ):
#                         g = a[p][j]
#                         h = a[j][q]
#                         a[p][j] = g - s * ( h + g * tau )
#                         a[j][q] = h + s * ( g - h * tau )
#                     for j in range(q+1, n, 1):#( j = q+1; j < n; ++j ):
#                         g = a[p][j]
#                         h = a[q][j]
#                         a[p][j] = g - s * ( h + g * tau )
#                         a[q][j] = h + s * ( g - h * tau )
#                     for j in range(n):#( j = 0; j < n; ++j ):
#                         g = v[j][p]
#                         h = v[j][q]
#                         v[j][p] = g - s * ( h + g * tau )
#                         v[j][q] = h + s * ( g - h * tau )
#         for p in range(n):#( p = 0; p < n; ++p ):
#             #d[p] = ( b[p] += z[p] )
#             b[p] += z[p]
#             d[p] = b[p]
#             z[p] = 0.
#     #delete[] b;

A = [[0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0],
     [0, 0, 0, 0, 0]]

C = [[0.20, 0, 0.2, 0, 0],
     [0, 0.20, 0, 0.2, 0],
     [0.2, 0, 0.2, 0, 0.2],
     [0, 0.2, 0, 0.2, 0],
     [0, 0, 0.2, 0, 0.2]]

D = [[2.330, 0.81, 0.67, 0.92, -0.53],
     [0.81, 2.33, 0.81, 0.67, 0.92],
     [0.67, 0.81, 2.33, 0.81, 0.92],
     [0.92, 0.67, 0.81, 2.33, -0.53],
     [-0.53, 0.92, 0.92, -0.53, 2.33]]

k=int(input("K: "))

for i in range(len(C)):
    for j in range(len(C[0])):
        C[i][j] *= k

for i in range(len(D)):
    for j in range(len(D[0])):
        A[i][j] = D[i][j] + C[i][j]

# A = [[17.0, 6.0],
#      [6.0, 8.0]]
n = len(A)
v = [[0, 0], [0, 0]]
d = [[0, 0], [0, 0]]


# jacobii(n, A, d, v)
# print(v)
# print(d)


def jacobi(a, tol=1.0e-9):  # Jacobi method

    def maxElem(a):  # Find largest off-diag. element a[k,l]
        n = len(a)
        aMax = 0.0
        for i in range(n - 1):
            for j in range(i + 1, n):
                if abs(a[i][j]) >= aMax:
                    aMax = abs(a[i][j])
                    k = i;
                    l = j
        return aMax, k, l

    def rotate(a, p, k, l):  # Rotate to make a[k,l] = 0
        n = len(a)
        aDiff = a[l][l] - a[k][k]
        if abs(a[k][l]) < abs(aDiff) * 1.0e-36:
            t = a[k][l] / aDiff
        else:
            phi = aDiff / (2.0 * a[k][l])
            t = 1.0 / (abs(phi) + math.sqrt(phi ** 2 + 1.0))
            if phi < 0.0:
                t = -t
        c = 1.0 / math.sqrt(t ** 2 + 1.0)
        s = t * c
        tau = s / (1.0 + c)
        temp = a[k][l]
        a[k][l] = 0.0
        a[k][k] = a[k][k] - t * temp
        a[l][l] = a[l][l] + t * temp
        for i in range(k):  # Case of i < k
            temp = a[i][k]
            a[i][k] = temp - s * (a[i][l] + tau * temp)
            a[i][l] = a[i][l] + s * (temp - tau * a[i][l])
        for i in range(k + 1, l):  # Case of k < i < l
            temp = a[k][i]
            a[k][i] = temp - s * (a[i][l] + tau * a[k][i])
            a[i][l] = a[i][l] + s * (temp - tau * a[i][l])
        for i in range(l + 1, n):  # Case of i > l
            temp = a[k][i]
            a[k][i] = temp - s * (a[l][i] + tau * temp)
            a[l][i] = a[l][i] + s * (temp - tau * a[l][i])
        for i in range(n):  # Update transformation matrix
            temp = p[i, k]
            p[i][k] = temp - s * (p[i][l] + tau * p[i][k])
            p[i][l] = p[i][l] + s * (temp - tau * p[i][l])

    n = len(a)
    maxRot = 5 * (n ** 2)  # Set limit on number of rotations
    p = identity(n) * 1.0  # Initialize transformation matrix
    for i in range(maxRot):  # Jacobi rotation loop
        aMax, k, l = maxElem(a)
        if aMax < tol: return diagonal(a), p
        rotate(a, p, k, l)
    print('Jacobi method did not converge')


lam, x = jacobi(A)
print(lam, '\n', x)
