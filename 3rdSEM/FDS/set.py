def union(set1,set2):
    un=[]
    for i in set1:
        un.append(i)
    for j in set2:
        if j in un:
            pass
        else:
            un.append(j)
    return un

def inter(set1,set2):
    int=[]
    for i in set1:
            if i in set2:
                int.append(i)
    return int 

def sub(set1,set2):
    s=[]
    for i in set1:
        s.append(i)
    for j in set2:
        if j in sub:
            s.remove(j)
        else:
            pass
    return s

intersection=[]
AUB=[]
subtraction=[]
print(sub(setA,setB))
print(sub(setB,setA))
AUB=union(setA,setB)
print(AUB)
intersection=inter(setA,setB)
print (intersection)
