if __name__ == '__main__':
    def frequency_check(character,samplestr):
        count=0
        for i in range(len(samplestr)):
            if samplestr[i]==character:
                count=count+1
        return count
    
    def palindrome(samplestring):
        rev=samplestring[::-1]
        if rev==samplestring:
            print("The given string is palindrome")
        else:
            print("The given string is not palindrome")

    def lon_word(str1):
        list1=list(str1.split(" "))
        count=0
        for i in list1:
            if(len(i)>count):
                count=len(i)
        for i in list1:
            if(len(i)==count):
                print("Longest word in the string:",i)

    def sub_check(string2,substring1):
        for i in range(len(substring1)):
            for j in range(len(string2)):
                if(string2[j]==substring1[i]):

                    print(j,end="")
                    break

    def fre_word(string1):
        list1=list(string1.split(" "))
        count=0
        for i in range(len(list1)):
            for j in range(len(list1)):
                if(list1[i]==list1[j]):
                    count=count+1
                    print(list1[i])
            print(count)
            
    def fre_occ(string1):
        list1=list(string1.split(" "))
        set1=set(list1)
        for i in set1:
            count=0
            for j in list1:
                if i==j:
                    count=count+1
                    print(i,count)
    print("----------MENU----------")
    print("1.To display word with the longest length")
    print("2.To determine the frequency of occurrence of particular character in the string")
    print("3.To check whether given string is palindrome or not")
    print("4.To display index of first appearance of the substring")
    print("5.To count the occurrences of each word in a given string")
    choice=int(input("Enter your choice:"))
    if(choice==1):
        string1=input("Enter the string:")
        print(lon_word(string1))
    if(choice==2):
        string=input("Enter the string:")
        character=input("Enter the character:")
        print("Frequency of occurrence of the character in the string is",frequency_check(character,string))
    if(choice==3):
        string=input("Enter the string:")
        print(palindrome(string))
    if(choice==4):
        string2=input("Enter the string:")
        substring1=input("Enter the substring:")
        print(sub_check(string2,substring1))
    if(choice==5):
        string3=input("Enter the string:")
        print(fre_occ(string3))
