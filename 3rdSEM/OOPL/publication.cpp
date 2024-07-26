//AUTHOR : MISBAH BAGWAN,21487
//OOPEXP3
#include <iostream>
#include <string.h>
using namespace std;

class Publication
{
    protected:
    string title;
    float price;
    public:
    Publication()
    {
        title="";
        price=0.0;
    }
        void get()
        {
            try
            {
                cout<<"Enter title : "<<endl;
                cin>>title;
                cout<<"Enter price : "<<endl;
                cin>>price;
                if(price>=5000.00)
                {
                    title="";
                    price=0.0;
                    throw(price);
                }
                
            }
            catch(float price)
            {
            //title="";
            //price=0.0;
            cout<<"Invalid price.No books greater than 5000"<<endl;
            cout<<"Data members set to zero values."<<endl;
            
            }
        }
        void put()
        {
            cout<<"Title : "<<title<<endl;
            cout<<"Price : "<<price<<endl;
        }
    
};
class Book:public Publication
{
    int pages;
    public:
    Book()
    {
        pages=0;
    }
    void getdata()
    {
        get();
        cout<<"Enter pages : "<<endl;
        cin>>pages;
    }
    void putdata()
    {
        put();
        cout<<"Pages : "<<pages<<endl;
    }
    ~Book()
    {
        
    }
};
class Tape:public Publication
{
    int minutes;
    public:
    Tape()
    {
        minutes=0;
    }
    void getdata()
    {
        get();
        cout<<"Enter Minutes : "<<endl;
        cin>>minutes;
        try
        {
            if(minutes>=1000)
            {
                cout<<"No Audio Book Available having more than 10 hours Playing time "<<endl;
                minutes=0;
               throw(minutes);
            }
        }
        catch(int minutes)
        {
            cout<<"Data members set to zero values."<<endl;
            title="";
            price=0.0;
            minutes=0;
        }
    }
    void putdata()
    {
        put();
        cout<<"Minutes : "<<minutes<<endl;
    }
    ~Tape()
    {
        
    }
};
int main() 
{
    Book b;
    Tape t;
    b.getdata();
    t.getdata();
    b.putdata();
    t.putdata();
   
    return 0;
}

// #include <iostream>
// using namespace std;

// int main() 
// { 
//     int choice;
//     cout<<"enter choice : "<<endl;
//     while(1)
//     {
//         cout<<"1.HI "<<endl;
//         cout<<"2.HELLO "<<endl;
//         cout<<"3.HOW ARE YOU "<<endl;
//         cout<<"4.EXIT "<<endl;
//         cin>>choice;
//         switch(choice)
//         {
//         case 1:
//             cout<<"you selected 1 "<<endl;
//         break;
//         case 2:
//             cout<<"you selected 2 "<<endl;
//         break;
//         case 3:
//             cout<<"you selected 3 "<<endl;
//         break;
//         case 4:
//         exit(0);
//         }
//     }
//      cout<<"you exited switch case : "<<endl;
//     return 0;
// }
