//Author :  Misbah Bagwan 21487
//OOP EX2
#include <iostream>
#include <string>
using namespace std;
class stud
{
private:
    int rno = 21487;

public:
    static int count;
    string nm, dob, bg;
    float ht, wt;
    float t1, t2;
    string ino, add;
    long int tel;
    long int lic;

    stud() // default constructor
    {
        nm = " ";
        dob = " ";
        bg = " ";
        ino = " ";
        add = " ";
        ht = 0.0;
        wt = 0.0;
        tel = 000;
        lic = 000;
        rno = 0;
    }
    stud(string nm, string dob, string bg, float ht, float wt, string ino, string add, long int tel, long int lic)
    { // parameterised constructor

        this->nm = nm;
        this->dob = dob;
        this->bg = bg;
        this->ht = ht;
        this->wt = wt;
        this->ino = ino;
        this->add = add;
        this->tel = tel;
        this->lic = lic;
        cout << "Inside parameterised Constructor " << endl;
        count++;
    }
    stud(stud &s)
    {
        // copy constructor
        nm = s.nm;
        dob = s.dob;
        bg = s.bg;
        ht = s.ht;
        wt = s.ht;
        ino = s.ino;
        add = s.ino;
        add = s.add;
        tel = s.tel;
        cout << "Inside copy constructor : " << endl;
        // count++;
        // s.put(); //
    }
    void get()
    {
        cout << "Enter Name : " << endl;
        cin >> nm;
        cout << "Enter Date of Birth : " << endl;
        cin >> dob;
        cout << "Enter BloodGroup : " << endl;
        cin >> bg;
        cout << "Enter Height : " << endl;
        cin >> ht;
        cout << "Enter  Weight : " << endl;
        cin >> wt;
        cout << "Enter Insurance Policy Number  : " << endl;
        cin >> ino;
        cout << "Enter Address : " << endl;
        cin >> add;
        cout << "Enter Telephone Number : " << endl;
        cin >> tel;
        cout << "Enter Driving License Number : " << endl;
        cin >> lic;
        count++;
    }

    inline float cal(float t1, float t2)
    {
        float avg;
        t1 = t1;
        t2 = t2;
        avg = (t1 + t2) / 2;
        return avg;
    }
    void put()
    {

        cout << "      Name    DOB    Bloodgroup   Height and Weight  InsurancePolicy  Address  Telephone Number   Driving License Number " << endl;
        cout << count << "      " << nm << " " << dob << "       " << bg << "             " << ht << "cm  " << wt << "kg       " << ino << "           " << add << "              " << tel << "           " << lic << endl;
    }
    static void getcount()
    {
        cout << count << endl;
    }
    ~stud()
    {
        cout << "Destructor called" << endl;
    }
};
int stud::count = 0;
int main()
{
    int choice;
    stud s1, s2, s3, s4, s5;
    int size;
    stud *p;
    cout << "Please Enter choice : " << endl;
    while (1)
    {
        cout << "1.Add single Record " << endl;
        cout << "2.Duplicate Above Record" << endl;
        cout << "3.Call Inline Function " << endl;
        cout << "4.Enter data for multiple students " << endl;
        // cout << "5.Enter data for multiple students " << endl;
        cout << "5.Get total number of students added till now" << endl;
        cout << "6.Free memory occupied by objects " << endl;
        cout << "7.Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            // stud s1;
            s1.get();
            cout << "hi";
            break;
        case 2:
            // s2.get();
            s3 = stud(s2);
            s3.put();
            break;
        case 3:
            cout << s4.cal(17.8, 14.9) << endl;
            break;
        case 4:

            cout << "Enter the number of students you want to record : " << endl;
            cin >> size;
            // stud s[size];
            //  stud *p = new stud[size];
            p = new stud[size];
            for (int i = 0; i < size; i++)
            {
                p[i].get();
                // stud::count++;
                p[i].put();
            }
            break;
        case 5:
            cout << "Number of students added till now : " << endl;
            stud::getcount();
            break;
        case 6:
            delete p;
            break;
        case 7:
            exit(0);
            break;
        }
    }

    /*stud s1;
    s1.get();
    stud s2(s1);
    s2.put();
    stud s3("misbah", "1/3/4", "o+", 157.2, 48.5, "340091", "katraj", 24365260, 9898901); // using paramterised constructor to pass values
    s3.put();
    cout << "Inline function returning avg : " << s1.cal(17.8, 14.9) << endl;
    int size;
    cout << "Enter the number of students you want to record : " << endl;
    cin >> size;
    stud s[size];
    stud *p = new stud[size];

    for (int i = 0; i < size; i++)
    {
        p[i].get();
        // stud::count++;
        p[i].put();
    }
    cout << "Number of students added till now : " << endl;
    stud::getcount();
    delete p;*/
    return 0;
}

