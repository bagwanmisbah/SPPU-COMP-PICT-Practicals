#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    int rno;
    string name;
    char div;
    string address;
    student()
    {
    }
};
void add()
{
    student s;
    cout << "Enter rollno: " << endl;
    cin >> s.rno;
    cout << "Enter name of student to be added: " << endl;
    cin >> s.name;
    cout << "Enter the division of Student: " << endl;
    cin >> s.div;
    cout << "Enter the address of Student: " << endl;
    cin >> s.address;

    ofstream write;
    write.open("Students.txt", ios::app);
    write << "\n"
          << s.rno;
    write << "\n"
          << s.name;
    write << "\n"
          << s.div;
    write << "\n"
          << s.address;
    write.close();
}
void display(student s)
{
    cout << "________________________________" << endl;
    cout << "Roll Number- " << s.rno << endl;
    cout << "Name- " << s.name << endl;
    cout << "Division- " << s.div << endl;
    cout << "Address- " << s.address << endl;
    cout << "________________________________" << endl;
    cout << endl;
}
void readRecord()
{
    student s;
    ifstream read;
    read.open("Students.txt");
    while (!read.eof()) // while we don't reach end of line
    {
        read >> s.rno;
        read >> s.name;
        read >> s.div;
        read >> s.address;
        display(s);
    }
    read.close();
}
int search(int roll)
{
    student s;
    ifstream read;
    read.open("Students.txt");
    while (!read.eof()) // while we don't reach end of line
    {
        read >> s.rno;
        read >> s.name;
        read >> s.div;
        read >> s.address;
        if (s.rno == roll)
        {
            cout << "Student's Record found " << endl;
            return s.rno;
        }
    }
    read.close();
    cout << "Students record not found " << endl;
    return -1;
}
void deleteRecord(int roll)
{
    roll = search(roll);
    if (roll == -1)
    {
        cout << "Student's record not found " << endl;
        return;
    }
    else
    {
        student s;
        ofstream write;
        write.open("temp.txt", ios::app);
        ifstream read;
        read.open("Students.txt");
        while (!read.eof())
        {
            read >> s.rno;
            read >> s.name;
            read >> s.div;
            read >> s.address;
            if (s.rno != roll)
            {
                write << "\n"
                      << s.rno;
                write << "\n"
                      << s.name;
                write << "\n"
                      << s.div;
                write << "\n"
                      << s.address;
            }
        }
        write.close();
        read.close();
        remove("Students.txt");
        rename("temp.txt", "Students.txt");
        cout << "Students record is deleted successfully" << endl;
    }
}
int main()
{
    int choice;
    while (true)
    {
        cout << "-----STUDENT RECORDS-----" << endl;
        cout << "Enter 1 for adding a record" << endl;
        cout << "Enter 2 for displaying the records" << endl;
        cout << "Enter 3 for searching a record" << endl;
        cout << "Enter 4 for deleting a record" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            readRecord();
            break;
        case 3:
            int roll_number;
            cout << "Enter roll number of the student to be searched-\n";
            cin >> roll_number;
            search(roll_number);
            break;
        case 4:
            cout << "Enter roll number of the student to be deleted-\n";
            cin >> roll_number;
            deleteRecord(roll_number);
            break;
        case 0:
            exit(0);
            break;
        }
    }
}