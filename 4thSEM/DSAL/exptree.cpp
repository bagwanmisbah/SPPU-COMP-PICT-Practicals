
// Construct an expression tree from the given prefix expression (e.g. +--a*bc/def) and
// perform following operations on it
// 1) traverse it using non recursive post order traversal
// 2) Count and Display operands in given expression
// 3) Count and display operators in given expression
// pre:+--a*bc/def
// post:abc*-de/-f+
#include <iostream>
#include <string.h>
using namespace std;
class node
{
public:
    char data;
    node *left;
    node *right;
};
class tree
{
    char prefix[20];

public:
    node *top;
    void exp(char[]);
    void display(node *);
    void postorder(node *);
    int operandCount(char[]);
    int operatorCount(char[]);
};
class stack
{
    node *data[30];
    int top;

public:
    stack()
    {
        top = -1;
    }
    int empty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
    void push(node *p)
    {
        data[++top] = p;
    }
    node *pop()
    {
        return (data[top--]);
    }
};
void tree::exp(char prefix[])
{
    char c;
    stack s;
    node *t1, *t2; // going to be right and left child of node
    int len, i;
    len = strlen(prefix);
    for (i = len - 1; i >= 0; i--)
    {
        top = new node;
        top->left = NULL;
        top->right = NULL;
        if (isalpha(prefix[i]))
        {
            top->data = prefix[i];
            s.push(top);
        }
        else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/')
        {
            t2 = s.pop();
            t1 = s.pop();
            top->data = prefix[i];
            top->left = t2;
            top->right = t1;
            s.push(top);
        }
    }
    top = s.pop();
}

void tree::display(node *root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << root->data;
        display(root->right);
    }
}
void tree::postorder(node *top)
{
    stack s1, s2;
    node *T = top;
    cout << "\n";
    s1.push(T);
    while (!s1.empty())
    {
        T = s1.pop();
        s2.push(T);
        if (T->left != NULL)
            s1.push(T->left);
        if (T->right != NULL)
            s1.push(T->right);
    }
    while (!s2.empty())
    {
        top = s2.pop();
        cout << top->data;
    }
}
int tree::operandCount(char prefix[])
{
    int count = 0;
    int sz = strlen(prefix);
    char c;
    for (int i = 0; i < sz; i++)
    {
        if (prefix[i] >= 'a' && prefix[i] <= 'z' || prefix[i] >= 'A' && prefix[i] <= 'Z' || prefix[i] >= '0' && prefix[i] >= '9')
        {
            count++;
        }
    }
    return count;
}
int tree::operatorCount(char prefix[])
{
    int count = 0;
    int sz = strlen(prefix);
    char c;
    for (int i = 0; i < sz; i++)
    {
        if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' /*|| prefix[i] >= '0' || prefix[i] >= '9'*/)
        {
            count++;
        }
    }
    return count;
}
int main()
{
    char expr[20];
    tree t;
    cout << "Enter Prefix expression :";
    cin >> expr;
    t.exp(expr);
    t.display(t.top);
    cout << "\nPostfix expression is: ";
    t.postorder(t.top);
    cout << "\nNumber of operands:" << t.operandCount(expr);
    cout << "\nNumber of operators:" << t.operatorCount(expr);
    return 0;
} // abc*-de/-f+
