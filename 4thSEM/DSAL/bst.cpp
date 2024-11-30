#include <iostream>
#include <stdlib.h>
using namespace std;

class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node *root = NULL;
    node()
    {
    }
    node(int d)
    {
        data = d;
    }
    node *insert(node *temp, int d)
    {
        if (temp == NULL)
        {
            node *newnode = new node(d);
            temp = newnode;
        }
        else if (temp->data > d)
        {
            temp->left = insert(temp->left, d);
        }
        else
        {
            temp->right = insert(temp->right, d);
        }
        return temp;
    }
    void AscendingIterativeInorder(node *root);
    void DescendingIterativeInorder(node *root);
    void search(node *temp, int el, int &count);
    void max(node *temp);
    void min(node *temp);
    void deleteNode(int d);
    void mirror()
    {
        _mirror(root);
    }
    void _mirror(node *n)
    {
        node *rchild = n->right;
        node *lchild = n->left;
        n->left = rchild;
        n->right = lchild;
        if (lchild)
            _mirror(lchild);
        if (rchild)
            _mirror(rchild);
    }
void currentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}
void levelOrder(node *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        currentLevel(root, 1);
    }
}
int height(node *root)
{
    int lh, rh;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        lh = height(root->left);
        rh = height(root->right);
        if (lh > rh)
        {
            return (lh + 1);
        }
        else
        {
            return (rh + 1);
        }
    }
}
    friend class stack;
};
class stack
{
    node *s[30];
    int top = -1;

public:
    stack()
    {
        top = -1;
    }
    bool empty()
    {
        return (top == -1);
    }
    void push(node *temp)
    {
        s[++top] = temp;
    }
    void pop()
    {
        top--;
    }
    node *gettop()
    {
        return s[top];
    }
    friend class node;
};

void node::AscendingIterativeInorder(node *root)
{
    stack st;
    node *temp = root;
    while (!st.empty() || temp != NULL)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = st.gettop();
            st.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}
void node::DescendingIterativeInorder(node *root)
{
    stack st;
    node *temp = root;
    while (!st.empty() || temp != NULL)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->right;
        }
        else
        {
            temp = st.gettop();
            st.pop();
            cout << temp->data << " ";
            temp = temp->left;
        }
    }
}
// void node::search(node *temp, int el)
// {
//     int count = 0;
//     if (temp != NULL)
//     {
//         if (temp->data == el)
//         {
//             count++;
//             cout << "Element found  ,  " << count << "Comparisons made" << endl;
//             count++;
//         }
//         if (temp->data > el)
//         {
//             count++;
//             search(temp->left, el);
//             count++;
//         }
//         if (temp->data < el)
//         {
//             count++;
//             search(temp->right, el);
//             count++;
//         }
//     }
//     else
//     {
//         cout << "Element not found , " << count << "Comparisons made" << endl;
//     }
// }
void node::search(node *temp, int el, int &count)
{
    if (temp != NULL)
    {
        if (temp->data == el)
        {
            count++;
            cout << "Element found, " << count << " comparisons made" << endl;
        }
        else if (temp->data > el)
        {
            count++;
            search(temp->left, el, count);
        }
        else
        {
            count++;
            search(temp->right, el, count);
        }
    }
    else
    {
        cout << "Element not found, " << count << " comparisons made" << endl;
    }
}
void node::max(node *temp)
{
    // int max;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    cout << "Maximum value = " << temp->data << endl;
}
void node::min(node *temp)
{
    // int max;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    cout << "Maximum value = " << temp->data << endl;
}
void node::deleteNode(int d)
{
    node *current = root;
    node *parent = NULL;
    while (current != NULL && current->data != d)
    {
        parent = current;
        if (current->data > data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    if (current == NULL)
    {
        cout << "Node is not present " << endl;
    }
    if (current->left == NULL || current->right == NULL)
    {
        node *newnode = new node();
        if (current->left == NULL)
        {
            newnode = current->left;
        }
        if (current->right == NULL)
        {
            newnode = current->right;
        }
        if (parent->left == current)
        {
            parent->left = newnode;
        }
        if (parent->right == newnode)
        {
            parent->right = newnode;
        }
        delete current;
    }
    else
    {
        node *prev = NULL;
        node *temp;
        temp = current->right;
        while (temp->left != NULL)
        {
            prev = temp;
            temp = temp->left;
        }
        prev != NULL ? prev->left = temp->right : current->right = temp->right;
        current->data = temp->data;
        delete temp;
    }
}

int main()
{
    node n;
    int t;
    cout << "Enter no of elements: " << endl;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int y;
        cout << "Number: ";
        cin >> y;
        n.root = n.insert(n.root, y);
    }
    int ch;
    while (true)
    {
        cout << "\n______________________" << endl;
        cout << "1.Insert a New Node: " << endl;
        cout << "2.Iterate in Ascending order : " << endl;
        cout << "3.Iterate in Descending order : " << endl;
        cout << "4.Get Minimum and Maximum value: " << endl;
        cout << "5.Delete a node: " << endl;
        cout << "6.Search for a node: " << endl;
        cout << "7.Exit " << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        cout << "______________________" << endl;
        switch (ch)
        {
        case 1:
            int x;
            cout << "Number: ";
            cin >> x;
            n.root = n.insert(n.root, x);
            break;

        case 2:
            n.AscendingIterativeInorder(n.root);
            break;

        case 3:
            n.DescendingIterativeInorder(n.root);
            break;

        case 4:
            n.min(n.root);
            n.max(n.root);
            break;

        case 5:
            int nodeToBeDeleted;
            cout << "Enter node to be deleted: ";
            cin >> nodeToBeDeleted;
            n.deleteNode(nodeToBeDeleted);
            cout << "Tree after deletion of " << nodeToBeDeleted << endl;
            n.AscendingIterativeInorder(n.root);
            break;

        case 6:
            int nodeToSearch;
            int cnt = 0;
            cout << "Enter the node to be searched: ";
            cin >> nodeToSearch;
            n.search(n.root, nodeToSearch, cnt);
            break;

            // case 7:
            //     exit(0);
            //     break;
        }
    }
    return 0;
}