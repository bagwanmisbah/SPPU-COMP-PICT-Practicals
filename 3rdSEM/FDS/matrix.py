a=[[4,5,7],[8,9,1],[2,4,6]]
b=[[4,5,7],[8,9,1],[2,4,6]]
print("Matrix A :")
for i in a:
    print(i)
print("Matrix B :")
for i in b:
    print(i)

def add(a,b):
    C=[[0,0,0] , [0,0,0,] , [0,0,0,]]
    for i in range(len(a)):
        for j in range(len(a)):
            C[i][j]=a[i][j]+b[i][j]
    print("Addition :")
    for i in C:
        print(i)

def sub(a,b):
    C=[[0,0,0] , [0,0,0,] , [0,0,0,]]
    for i in range(len(a)):
        for j in range(len(a)):
            C[i][j]=a[i][j]-b[i][j]
    print("Subtraction :")
    for i in C:
        print(i)

def mul(a,b):
    C=[[0,0,0],[0,0,0],[0,0,0]]
    for i in range(len(a)):
        for j in range(len(b)):
            for k in range(len(b)):
                C[i][j]=C[i][j]+a[i][k]*b[k][j]
    print("Multiplication :")
    for i in C:
        print(i)

def trans(a,):
    C=[[0,0,0],[0,0,0],[0,0,0]]
    for i in range(3):
            for j in range(len(a[0])):
                C[i][j]=a[j][i]
    print("Transpose :")
    for i in C:
        print(i)

#add(a,b)
#sub(a,b)
#mul(a,b)
trans(a)
