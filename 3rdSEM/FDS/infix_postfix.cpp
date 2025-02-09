#include <iostream>
using namespace std;

char stack[10];
int top=-1;

void convert()
{
    char infix[20];
    char postfix[20];
    int j=0;
    int i=0;

    cout<<"Enter Expression  : "<<endl;
    cin>>infix;

    for(i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='('||infix[i]=='{'||infix[i]=='[')
        {
            top++;
            stack[top]=infix[i];
        }
        else if(infix[i]=='+'||infix[i]=='*'||infix[i]=='/'||infix[i]=='-')
        {
            top++;
            stack[top]=infix[i];
        }
        else if(infix[i]=='a'||infix[i]=='b'||infix[i]=='c'||infix[i]=='d')
        {
            postfix[j]=infix[i];
            j++;
        }
        else
        {
            switch(infix[i])
            {
                case ')':
                while(stack[top]!='(')
                {
                    postfix[j]=stack[top];
                    j++;
                    top--;
                }
                top--;
                break;

                case '}':
                while(stack[top]!='{')
                {
                    postfix[j]=stack[top];
                    j++;
                    top--;
                }
                top--;
                break;

                case ']':
                while(stack[top]!='[')
                {
                    postfix[j]=stack[top];
                    j++;
                    top--;
                }
                top--;
                break;
            }
        }
    }
    postfix[j]='\0';
    cout<<"Postfix : "<<postfix;
}
int main()
{
    cout<<"-------------------infix to postfix-----------------------------"<<endl;
    convert();
    return 0;
}
