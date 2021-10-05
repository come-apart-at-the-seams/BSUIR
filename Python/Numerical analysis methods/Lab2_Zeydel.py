A=[[0, 0, 0, 0, 0],
   [0, 0, 0, 0, 0],
   [0, 0, 0, 0, 0],
   [0, 0, 0, 0, 0],
   [0, 0, 0, 0, 0]]

C=[[0.02, 0, -0.02, 0, 0],
   [0.01, 0.01, -0.02, 0, 0],
   [0, 0.01, 0.01, 0, -0.02],
   [0, 0, 0.01, 0.01, 0],
   [0, 0, 0, 0.01, 0.01]]

D=[[1.33, 0.21, 0.17, 0.12, -0.13],
   [-0.13, -1.33, 0.11, 0.17, 0.12],
   [0.12, -0.13, -1.33, 0.11, 0.17],
   [0.17, 0.12, -0.13, -1.33, 0.11],
   [0.11, 0.67, 0.12, -0.13, -1.33]]

b=[1.2, 2.2, 4.0, 0, -1.2]

k=int(input("K: "))

for i in range(len(C)):
    for j in range(len(C[0])):
        C[i][j] *= k

for i in range(len(D)):
    for j in range(len(D[0])):
        A[i][j] = D[i][j] + C[i][j]


 #x0=b/a + x1/a + x2/a
for i in range(len(A)):
    a = A[i][i]
    for j in range(len(A[0])):
        A[i][j] = -(A[i][j]) / a
        if(i==j):
            A[i][j] = b[i] / a

x = []
x_old = []
dx = []
for i in range(len(A)):
    x.append(0)
    x_old.append(x[i])
    dx.append(1.23)

step = 0

while True:
    for i in range(len(A)):
        for j in range(len(A[0])):
            if(i!=j):
                x[i] += A[i][j] * x_old[j]
            else:
                x[i] += A[i][j]
        dx[i]  = abs(x[i] - x_old[i])
        x_old[i] = x[i]
        x[i] = 0

    for i in range(len(A)):

        if(i==0):
            maxD = dx[i]
        else:
            if(maxD < dx[i]):
                maxD = dx[i]

    step+=1
    if maxD < 0.0001:
        break

#answer
for i in range(len(A)):
    print(" X", i, " = ", x_old[i])
print("Steps = ", step)
