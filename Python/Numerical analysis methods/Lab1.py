A=[[0, 0, 0, 0, 0],
   [0, 0, 0, 0, 0],
   [0, 0, 0, 0, 0],
   [0, 0, 0, 0, 0],
   [0, 0, 0, 0, 0]]

C=[[0.20, 0, 0.2, 0, 0],
   [0, 0.20, 0, 0.2, 0],
   [0.2, 0, 0.2, 0, 0.2],
   [0, 0.2, 0, 0.2, 0],
   [0, 0, 0.2, 0, 0.2]]

D=[[2.330, 0.81, 0.67, 0.92, -0.53],
   [0.53, 2.33, 0.81, 0.67, 0.92],
   [0.92, -0.53, 2.33, 0.81, 0.67],
   [0.67, 0.92, -0.53, 2.33, 0.81],
   [0.81, 0.67, 0.92, -0.53, 2.33]]

b=[4.2, 4.2, 4.2, 4.2, 4.2]

A1=[[0,0,0],
   [0,0,0],
   [0,0,0]]
C1=A1
D1=[[1,2,-1],
   [2,-6,-3],
   [3,2,-5]]
b1=[9,13,-1]

k=int(input("K: "))

for i in range(len(C)):
    for j in range(len(C[0])):
        C[i][j] *= k

for i in range(len(D)):
    for j in range(len(D[0])):
        A[i][j] = D[i][j] + C[i][j]

print(A)

for i in range(len(A)):

    if(abs(A[0][0]) < abs(A[i][0])):
        cp = A[0]
        A[0]=A[i]
        A[i]=cp
        cpp = b[0]
        b[0]=b[i]
        b[i] = cpp



print (A)

#iterate through columns
for j in range(len(A[0])):
    i0=j
    print(i0)
    for i in range(j + 1, len(A)):
        if (A[i][j] != 0):
            x = A[i][j] / A[i0][j]
            for jj in range(j, len(A[0])):
                A[i][jj] = A[i][jj] - (x * A[i0][jj])
                A[i][jj] = round(A[i][jj], 4)
                print("A[",i,"][",jj,"]= ",A[i][jj])
            b[i] = b[i] - (x * b[i0])
            b[i] = round(b[i], 4)
            print("b[", i, "]= ", b[i])
print(A)
print(b)

#iterate through columns
for j in range(len(A[0]) - 1, -1, - 1):
    i0 = j
    print(i0)
    for i in range(j - 1, -1, -1):
        if (A[i][j] != 0):
            x = A[i][j] / A[i0][j]
            for jj in range(j, len(A[0])):
                A[i][jj] = A[i][jj] - (x * A[i0][jj])
                A[i][jj] = round(A[i][jj], 4)

                print("A[", i, "][", jj, "]= ", A[i][jj])
            b[i] = b[i] - (x * b[i0])
            b[i] = round(b[i], 4)
            print("b[", i, "]= ", b[i])
print(A)
print(b)


for i in range(len(A)):
    if(A[i][i]!=0):

        a = round(b[i] / A[i][i], 4)
        print(" X", i, " = ", a)
    else:
        print("X",i," = R")