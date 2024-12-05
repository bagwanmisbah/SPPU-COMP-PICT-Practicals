#include <iostream>
using namespace std;

class Data_element
{
    int id;
    long long int telephone_no;

public:
    friend class hashtable;
    friend class hashtable2;
};

class hashtable
{
    Data_element hasharray[10];

public:
    hashtable()
    {
        for (int i = 0; i < 10; i++)
        {
            hasharray[i].id = -1;
            hasharray[i].telephone_no = 0;
        }
    }

    int hash_index(int key)
    {
        return (3 * key + 5) % 10;
    }

    void insert(int d, long long int t)
    {
        int index = hash_index(d);
        int temp = index;
        if (hasharray[index].id == -1)
        {
            hasharray[index].id = d;
            hasharray[index].telephone_no = t;
        }
        else
        {
            while (hasharray[index].id != -1)
            {
                if (index != 9)
                {
                    index += 1;
                }

                else
                {
                    index = 0;
                }

                if (index == temp)
                {
                    cout << "Hash Table Full" << endl;
                    return;
                }
            }
            hasharray[index].id = d;
            hasharray[index].telephone_no = t;
        }
    }

    void print()
    {
        cout << "\n===========================================" << endl;
        cout << "Index\t\tID\t\tTeleNo" << endl;
        cout << "===========================================" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << "\t\t" << hasharray[i].id << "\t\t" << hasharray[i].telephone_no << "\n";
        }
        cout << "===========================================" << endl;
    }

    void search(int d)
    {
        int comp = 1;
        int index = hash_index(d);
        int temp = index;
        if (hasharray[index].id == d)
            cout << "\n"
                 << hasharray[index].id << "\t" << hasharray[index].telephone_no;
        else
        {
            while (hasharray[index].id != d)
            {
                comp++;
                if (index != 9)
                {
                    index += 1;
                }

                else
                {
                    index = 0;
                }

                if (index == temp)
                {
                    cout << "\nElement not found" << endl;
                    cout << "\nNumber of comparisons required = " << comp << endl;
                    return;
                }
            }
            cout << "\n"
                 << hasharray[index].id << "\t" << hasharray[index].telephone_no;
        }
        cout << "\nNumber of comparisons required = " << comp << endl;
    }
};

class hashtable2
{
    Data_element hasharray[10];

public:
    hashtable2()
    {
        for (int i = 0; i < 10; i++)
        {
            hasharray[i].id = -1;
            hasharray[i].telephone_no = 0;
        }
    }

    int hash_index(int key)
    {
        return (3 * key + 5) % 10;
        // //  int hash_index(int key)
        // {
        //     return key % 10;
        // }
    }

    void insert(int d, long long int t)
    {
        int index = hash_index(d);
        int temp = index;
        if (hasharray[index].id == -1)
        {
            hasharray[index].id = d;
            hasharray[index].telephone_no = t;
        }
        else
        {
            int old = hasharray[index].id;
            int pos = hash_index(old);
            if (index == pos)
            {
                while (hasharray[index].id != -1)
                {
                    if (index != 9)
                    {
                        index += 1;
                    }

                    else
                    {
                        index = 0;
                    }

                    if (index == temp)
                    {
                        cout << "Hash Table Full" << endl;
                        return;
                    }
                }
                hasharray[index].id = d;
                hasharray[index].telephone_no = t;
            }
            else
            {
                // Retrieving information of old wrong placed element

                int oldeleid = hasharray[index].id;
                long long int oldeletelephone_no = hasharray[index].telephone_no;

                // placing new element at its correct position
                hasharray[index].id = d;
                hasharray[index].telephone_no = t;
                while (hasharray[index].id != -1)
                {
                    if (index != 9)
                    {
                        index += 1;
                    }

                    else
                    {
                        index = 0;
                    }

                    if (index == temp)
                    {
                        cout << "Hash Table Full" << endl;
                        return;
                    }
                }
                hasharray[index].id = oldeleid;
                hasharray[index].telephone_no = oldeletelephone_no;
            }
        }
    }

    void print()
    {
        cout << "\n===========================================" << endl;
        cout << "Index\t\tID\t\tTeleNo" << endl;
        cout << "===========================================" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << "\t\t" << hasharray[i].id << "\t\t" << hasharray[i].telephone_no << "\n";
        }
        cout << "===========================================" << endl;
    }

    void search(int d)
    {
        int comp = 1;
        int index = hash_index(d);
        int temp = index;
        if (hasharray[index].id == d)
            cout << "\n"
                 << hasharray[index].id << "\t" << hasharray[index].telephone_no;
        else
        {
            while (hasharray[index].id != d)
            {
                comp++;
                if (index != 9)
                {
                    index += 1;
                }

                else
                {
                    index = 0;
                }

                if (index == temp)
                {
                    cout << "\nElement not found" << endl;
                    cout << "\nNumber of comparisons required = " << comp << endl;
                    return;
                }
            }
            cout << "\n"
                 << hasharray[index].id << "\t" << hasharray[index].telephone_no;
        }
        cout << "\nNumber of comparisons required = " << comp << endl;
    }
};

int main()
{

    hashtable h1;
    hashtable2 h2;
    int id;
    long long int telno;
    int choice;
    while (true)
    {
        cout << "____________HASHING_______________" << endl;
        cout << "1.Insert without replacement : " << endl;
        cout << "2.Insert with replacement : " << endl;
        cout << "3.Display " << endl;
        cout << "4.Search " << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << "_____________________________________" << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter id: " << endl;
            cin >> id;
            cout << "Enter telelphone number: " << endl;
            cin >> telno;
            h1.insert(id, telno);
            break;
        case 2:
            cout << "Enter id: " << endl;
            cin >> id;
            cout << "Enter telelphone number: " << endl;
            cin >> telno;
            h2.insert(id, telno);
            break;
        case 3:
            cout << "With Replacement : " << endl;
            h1.print();
            cout << " Without Replacement :" << endl;
            h2.print();
            break;
        case 4:
            cout << "Search in LP with replacement :" << endl;
            cout << "Enter id to be searched: " << endl;
            cin >> id;
            h1.search(id);
            h2.search(id);
            break;
        default:
            cout << "Please enter a valid choice " << endl;
            break;
        }
    }

    /* h1.insert(37, 7588661666);
     h1.insert(23, 7588661667);
     h1.insert(13, 7588661668);
     h1.insert(14, 7588661669);
     h1.insert(78, 7588661660);
     h1.print();
     cout << "\nSearching" << endl;
     h1.search(23);
     h1.search(13);
     h1.search(19);
     h1.search(14);

     hashtable2 h;
     h.insert(37, 7588661666);
     h.insert(23, 7588661667);
     h.insert(13, 7588661668);
     h.insert(14, 7588661669);
     h.insert(78, 7588661660);
     h.insert(18, 9989078909);
     // h.insert(29, 9989039690);
     h.print();
     // h.insert(28, 9989078909);
     h.insert(29, 9989039690);

     h.insert(15, 9834547941);

     h.print();*/

    /*h.search(23);
    h.search(13);
    h.search(19);
    h.search(14);*/

    return 0;
}