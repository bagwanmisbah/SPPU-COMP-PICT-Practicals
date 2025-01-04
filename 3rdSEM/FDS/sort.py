# FDS (DATA STRUCTURE WITH PYTHON)
# SORTING :
def Bubble(a, size):
    for i in range(0,size-1):
            for j in range(0,size-1-i):
                if a[j]>a[j+1]:
                            temp=a[j]
                            a[j]=a[j+1]
                            a[j+1]=temp
    return a

def selection(a,size):
    for i in range(0,size-1):
        for j in range(i+1,size):
            if a[i]>a[j]:
                temp=a[i]
                a[i]=a[j]
                a[j]=temp
    return a

def insertion(a,size):
    for i in range(1,size):
        j=i-1
        x=a[i]
        while j>=0 and a[j]>x:
            a[j+1]=a[j]
            j=j-1
    a[j]=x   
    return a         

num=int(input("Enter size of array : "))
l1=[]
for i in range(0,num):
    n=int(input("enter element : "))
    l1.append(n)
print (Bubble(l1,num))
print(selection(l1,num))
print(insertion(l1,num))

 (a[j],a[j+1])=(a[j+1],a[j]) '''another easy way to swap without third variable''
