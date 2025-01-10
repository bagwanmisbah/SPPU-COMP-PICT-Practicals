class searching:
    def linear(self):
        l1=[10,20,30,40,50]
        size=len(l1)
        i=0;
        key=int(input("LINEAR SEARCH : ENTER THE ELEMENT TO BE SEARCHED: "))
        for i in range(size):
            if key==l1[i]:
                print("ELEMENT FOUND AT ", i + 1, "POSITION")
                break
            i=i+1
            if i==size:
                print("ELEMENT NOT FOUND ",i,"COMPARISONS MADE")
    
    def sen(self):
        l1=[11,22,33,44,55,66]
        size=len(l1)
        key = int(input("SENTINEL SEARCH :ENTER THE ELEMENT TO BE SEARCHED: "))
        last=l1[size-1]
        l1[size-1]=key
        i=0
        while key!=l1[i]:
            i=i+1
        if i<size or key==last:
            print("ELEMENT FOUND AT ", i + 1, "POSITION")
        else:
            print("ELEMENT NOT FOUND ", i, "COMPARISONS MADE")

    def binary(self):
        l1=[10,20,25,35,40,50]
        key=int(input("BINARY SEARCH : ENTER THE ELEMENT TO BE SEARCHED: "))
        size=len(l1)
        high=(size-1)
        low=0
        while low<=high:
            mid=int((low+high)/2)
            if key==l1[mid]:
                print("ELEMENT FOUND AT ",mid+1,"POSITION")
                break
            elif key < l1[mid]:
                high=(mid-1)
            elif key > l1[mid]:
                low=(mid+1)
        if low>high:
            print("ELEMENT NOT FOUND")

def fibonacci():
    key=int(input("Enter the element to be searched:"))
    f1=0
    f2=1
    fm=f1+f2
    while(fm<=key):
        f1=f2
        f2=fm
        fm=f1+f2
    if(fm==0):
        print("Element not found")
    offset=-1
    while(fm>=1):
        i=min(offset+fm-2,total_num-1)
        if(key==list[i]):
            print("Element found at index:",i)
            break
        elif(key>list[i]):
            fm=fm-1
            offset=i+1
        elif(key<list[i]):
            fm=fm-2

s1=searching()
s1.linear()
s1.sen()
s1.binary()
