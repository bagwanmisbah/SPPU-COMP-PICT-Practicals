#include <iostream>
using namespace std;

class st
{
    char stack[10];

public:
    void check()
    {
        int flag;
        char ch, exp[20];
        int i;
        int top = -1;
        cout << "Enter expression : " << endl;
        cin >> exp;
        flag = 0;

        for (i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            {
                top++;
                stack[top] = exp[i];
            }
            else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                ch = stack[top];
                top--;
                switch (exp[i])
                {
                case ')':
                    if (ch != '(')
                        flag = 1;
                    break;

                case '}':
                    if (ch != '(')
                        flag = 1;
                    break;

                case ']':
                    if (ch != '(')
                        flag = 1;
                    break;

                default:
                    cout << "Invalid";
                }
                if (flag == 1)
                    break;
            }
            else
            {
            }
        }
        cout << "Top " << top << endl;
        cout << "Flag:" << flag << endl;

        if (top != -1 || flag == 1)
            cout << "not well paranthesised " << endl;
        else
            cout << "Well paranthesised" << endl;
    }
};

int main()
{
    cout << "-------------------------------------" << endl;
    st s;
    s.check();
}
