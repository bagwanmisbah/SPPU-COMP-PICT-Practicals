// Group A :

// Experiment No. 1 : Implement a class Complex which represents the Complex Number data type. Implement the following
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers. 
// 4. Overload operators << and >> to print and read Complex Numbers.

//OOPEXP1
#include <iostream>
using namespace std;

class complex
{
    float real;
    float img;

public:
    complex()
    {
        real = 0.0;
        img = 0.0;
    }
    complex(float real, float img)
    {
        this->real = real;
        this->img = img;
    }
    friend complex operator+(complex c1, complex c2)
    {
        complex c3;
        c3.real = c1.real + c2.real;
        c3.img = c1.img + c2.img;
        return c3;
    }
    friend complex operator*(complex c1, complex c2)
    {
        complex c4;
        c4.real = c1.real * c2.real - c1.img * c2.img;
        c4.img = c1.real * c2.img + c1.img * c2.real;
        return c4;
    }

    friend istream &operator>>(istream &in, complex &c)
    {
        cout << "Enter complex number : " << endl;
        cout << "Enter real part : " << endl;
        in >> c.real;
        cout << "Enter img part : " << endl;
        in >> c.img;
    }
    friend ostream &operator<<(ostream &out, complex &c)
    {
        out << c.real << "  +  " << c.img << "i" << endl;
    }
};
int main()
{
    complex c1, c2, c3, c4;
    int choice;
    while (true)
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "1.Enter complex number values : " << endl;
        cout << "2.Display complex number  : " << endl;
        cout << "3.Add complex number  : " << endl;
        cout << "4.Multiply complex number  : " << endl;
        cout << "5.Exit " << endl;
        cout << "Please enter choice : " << endl;
        cout << "--------------------------------------------------------" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> c1;
            cin >> c2;
            break;

        case 2:
            cout << "Displaying complex number : " << endl;
            cout << c1;
            cout << c2;
            break;

        case 3:
            cout << "ADDITION : " << endl;
            c3 = c1 + c2;
            cout << c3;
            break;

        case 4:
            cout << "MULTIPLICATION : " << endl;
            c4 = c1 * c2;
            cout << c4;
            break;

        case 5:
            exit(0);
            break;

        default:
            cout << "Invalid Choice " << endl;
        }
    }
}


