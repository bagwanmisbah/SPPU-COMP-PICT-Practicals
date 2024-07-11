//OOP4 FILE
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class student
{
    string name;
    float marks;
    string div;
    char buff[100];
    fstream f;
    string line;

public:
    student()
    {
        name = "";
        div = "";
        marks = 0.0;
    }
    student(string name, string div, float marks)
    {
        this->name = name;
        this->div = div;
        this->marks = marks;
    }
    void accept()
    {
        cout << "Enter student Name : " << endl;
        cin >> name;
        cout << "Enter Student Division: " << endl;
        cin >> div;
        cout << "Enter Students Marks: " << endl;
        cin >> marks;
    }
    void insertInto()
    {
        f.open("StudentData.txt", ios::app);
        f << "Name : " << this->name;
        f << "Division: " << this->div;
        f << "Marks: " << this->marks;
        f << endl;
        f.close();
    }
    void readfrom()
    {
        f.open("StudentData.txt", ios::in);
        while (getline(f, line))
        {
            cout << line << endl;
        }
        f.close();
    }
};

int main()
{
    int n;
    cout << "Enter number of students you want to record: " << endl;
    cin >> n;
    student s[n];
    for (int i = 0; i < n; i++)
    {
        s[i].accept();
        s[i].insertInto();
    }
    for (int i = 0; i < n; i++)
    {
        s[i].readfrom();
    }
    return 0;
}
