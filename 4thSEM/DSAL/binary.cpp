#include <iostream>
using namespace std;

class node
{
    int data;
    node *left, *right;

public:
    node()
    {
        data = 0;
        left = right = NULL;
    }
    node(int d)
    {
        data = d;
    }
    friend class btree;
    friend class stack;
};
class stack
{
    node *s[30]; // created an array of pointer to node objects
    int top;

public:
    stack()
    {
        top = -1;
    }
    void push(node *x)
    {
        s[++top] = x;
    }
    void pop()
    {
        top--;
    }
    node *gettop()
    {
        return s[top];
    }
    bool isempty()
    {
        return (top == -1);
    }
    friend class node;
};
class btree
{
private:
    node *root;

public:
    btree()
    {
        root = NULL;
    }
    void create();
    node *insert();
    node *getroot()
    {
        return root;
    }
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
    void create()
    {
        root = insert();
    }
    node *insert()
    {
        node *temp;
        char ch;
        temp = new node();
        cout << "Enter data to be added in tree: " << endl;
        cin >> temp->data;
        cout << "Do you want to add data to left child of " << temp->data << "?(y/n) : ";
        cin >> ch;
        if (ch == 'y')
        {
            temp->left = insert();
        }
        cout << "Do you want to add data to right child of " << temp->data << "?(y/n) : ";
        cin >> ch;
        if (ch == 'y')
        {
            temp->right = insert();
        }
        return temp;
    }
    void InorderRecursive(node *temp)
    {
        if (temp != NULL)
        {
            InorderRecursive(temp->left);
            cout << temp->data << " ";
            InorderRecursive(temp->right);
        }
    }
    void PreorderRecursive(node *temp)
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            PreorderRecursive(temp->left);
            PreorderRecursive(temp->right);
        }
    }
    void PostorderRecursive(node *temp)
    {
        if (temp != NULL)
        {
            PostorderRecursive(temp->left);
            PostorderRecursive(temp->right);
            cout << temp->data << " ";
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
    int leaves(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        else
        {
            return (leaves(root->left) + leaves(root->right));
        }
    }
    int internalNodes(node *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
        {
            return 0;
        }
        else
        {
            return internalNodes(root->left) + internalNodes(root->right) + 1;
        }
    }
    void AscendingIterativeInorder(node *root)
    {
        stack st;
        node *temp = root;
        while (!st.isempty() || temp != NULL)
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
    void DescendingIterativeInorder(node *root)
    {
        stack st;
        node *temp = root;
        while (!st.isempty() || temp != NULL)
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

    void preorderIterative(node *root)
    {
        if (root == NULL)
            return;

        stack st;
        st.push(root);
        while (!st.isempty())
        {
            node *temp = st.gettop();
            st.pop();
            cout << temp->data << " ";
            if (temp->right)
                st.push(temp->right);
            if (temp->left)
                st.push(temp->left);
        }
    }
    void postorderIterative(node *root)
    {
        if (root == NULL)
            return;
        stack st;
        st.push(root);
        stack result;
        while (!st.isempty())
        {
            node *temp = st.gettop();
            st.pop();
            result.push(temp);
            if (temp->left)
                st.push(temp->left);
            if (temp->right)
                st.push(temp->right);
        }
        while (!result.isempty())
        {
            node *temp = result.gettop();
            result.pop();
            cout << temp->data << " ";
        }
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
};
// cout<<"Level wise printing: ";
// b1.LevelOrder(b1.getroot());