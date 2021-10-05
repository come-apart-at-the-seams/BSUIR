def func(poly, a):
    A = 0
    for i in range(len(poly)):
        A += poly[i] * a ** i
    return A



def negative(poly):
    neg = []
    for num in poly:
        neg.append(-num)
    return neg


def degree(poly):
    while poly and poly[-1] == 0:
        poly.pop()  # normalize
    return len(poly) - 1


def poly_div(N, D):
    dD = degree(D)
    dN = degree(N)
    if dD < 0: raise ZeroDivisionError
    if dN >= dD:
        q = [0] * dN
        while dN >= dD:
            d = [0] * (dN - dD) + D
            mult = q[dN - dD] = N[-1] / float(d[-1])
            d = [coeff * mult for coeff in d]
            N = [coeffN - coeffd for coeffN, coeffd in zip(N, d)]
            dN = degree(N)
        r = N
    else:
        q = [0]
        r = N
    return q, r


def poly_evaluation(poly, a, b):
    A = 0
    B = 0
    for i in range(len(poly)):
        A += poly[i] * a ** i
        B += poly[i] * b ** i
    return A, B


def sign(n):
    return -1 if n < 0 else 1


def shtyrm(F1, F2, a, b):
    f = [F1, F2]
    i = 0
    while True:
        i += 1
        g = poly_div(f[i - 1], f[i])
        f.append(negative(g[1]))
        if len(g[1]) == 1:
            break
    e = []
    for poly in f:
        e.append(poly_evaluation(poly, a, b))
    N_a = 0
    N_b = 0
    for i in range(len(e)):
        if i != 0:
            if sign(e[i][0]) != sign(e[i - 1][0]):
                N_a += 1
            if sign(e[i][1]) != sign(e[i - 1][1]):
                N_b += 1
    return N_a - N_b


##
def root_separetion(N, D, a, b):
    sht = shtyrm(N, D, -10, 10)
    if sht == 1:
        return a, b
    elif sht < 1:
        return 0
    else:
        i = 1
        while i < 10000:
            rng_iter = abs(a) + abs(b)
            step = rng_iter * i
            for j in range(step):
                fg = poly_evaluation(N, a+j, a+j+(1/i))
                if fg[0] * fg[1] < 0:
                    dfg = poly_evaluation(D, a+j, a+j+(1/i))
                    if dfg[0] * dfg[1] > 0:
                        return a+j, a+j+(1/i)
            else:
                i = i + 1
        else:
            print('Can not separated')
        for i in range(a, b - 1, 1):
            #print('i = '+str(i))
            fg = poly_evaluation(N, i, i + 0.5)
            if fg[0] * fg[1] < 0:
                dfg = poly_evaluation(D, i, i + 0.5)
                if dfg[0] * dfg[1] > 0:
                    return i, i + 0.5
        print('Can not separated')


##
def find1(N, a, b, eps): #1/2
    left = a
    right = b
    iterat = 0
    while True:
        x = (left+right)/2
        f=func(N,x)
        if f>0:
            right = x
        else:
            left=x
        iterat+=1
        if abs(f)<eps or iterat>20000 :
            break
    print('Half iterations = ')
    print(iterat)
    return x


##
def find2(N, a, b, eps): #Xord
    rez = b
    iterat = 0
    while True:
        f=func(N, rez)
        f0=func(N, a)
        rez = rez - f/(f-f0)*(rez-a)
        iterat+=1
        if abs(f)<eps or iterat>20000 :
            break
    print('Xord iterations = ')
    print(iterat)
    return rez
##
def find3(N, D, a, eps): #Newton
    iterat = 0
    while True:
        f=func(N, a)
        df=func(D, a)
        a=a-f/df
        iterat+=1
        if abs(f)<eps or iterat>20000 :
            break
    print('Newton iterations = ')
    print(iterat)
    return a
##
if __name__ == '__main__':
    print("POLYNOMIAL LONG DIVISION")
    N = [-70.9238, 60.6959, -14.4621, 1]
    D = [60.6959, -28.9242, 3, 0]
    #    N = [-1, 1, 3, 2]
    #    D = [1, 6, 6, 0]
    print("  %s / %s =" % (N, D))
    print(" %s remainder %s" % poly_div(N, D))
    print()
    print('shtyrm = ')
    print(shtyrm(N, D, -10, 10))
    print()
    print('root_separetion = ')
    print(root_separetion(N, D, -10, 10))
    print()
    print(find1(N, root_separetion(N, D, -10, 10)[0], root_separetion(N, D, -10, 10)[1], 0.0001))
    print()
    print(find2(N, root_separetion(N, D, -10, 10)[0], root_separetion(N, D, -10, 10)[1], 0.0001))
    print()
    print(find3(N, D, root_separetion(N, D, -10, 10)[0], 0.0001))