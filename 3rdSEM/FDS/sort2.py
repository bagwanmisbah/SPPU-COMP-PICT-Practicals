def quicksort(seq):
    length=len(seq)
    if length<=1:
        return seq
    else:
        pivot=seq.pop()

        greater=[]
        lower=[]

        for item in seq:
            if item>pivot:
                greater.append(item)
            else:
                lower.append(item)

    return quicksort(lower) +[pivot] +quicksort(greater)


class sort:
    def insertion():
        a=[]
        size=int(input("Enter size :"))
        for i in range(0,size):
            n=int(input("Enter elements :"))
            a.append(n)
    
        for i in range(1,len(a)):
            j=i
            while a[j-1]>a[j] and j>0:
                temp=a[j-1]
                a[j-1]=a[j]
                a[j]=temp
                j=j-1
        print(a)

    def shell():
        a=[]
        size=int(input("Enter size :"))
        for i in range(0,size):
            n=int(input("Enter elements :"))
            a.append(n)

        n=len(a)
        gap=n//2
        while  gap>0:
            for i in range(gap,n):
                temp=a[i]
                j=i
                while j>=gap and a[j-gap]>temp:
                    a[j]=a[j-gap]
                    j=j-gap
                a[j]=temp
            gap=gap//2
        print(a)

s=sort
s.shell()
