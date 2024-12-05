/* Beginning with an empty binary search tree. Construct the binary search tree by
inserting the values in given order. After constructing binary search tree perform
following operations 1) Insert a new node 2) Find numbers of node in longest
path 3) Minimum and maximum data value found in tree 4) Change a tree so that
the roles of the left and right pointers are swapped at every node 5)Search an
element*/

#include <iostream>
#include <math.h>
using namespace std;

class Bstnode
{
public:
  int data;
  Bstnode *left = NULL;
  Bstnode *right = NULL;
  Bstnode *root = NULL;
  Bstnode() {}
  Bstnode(int d)
  {
    data = d;
  }
  Bstnode *insert(Bstnode *temp, int d);
  void delet();
  void inorder(Bstnode *temp);
  int depth(Bstnode *temp);
  void minimum(Bstnode *temp);
  void maximum(Bstnode *temp);
  void search(Bstnode *temp, int ele);
  void mirror(Bstnode *temp);
int height(Bstnode *root)
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
void currentLevel(Bstnode *root, int level)
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
void levelOrder(Bstnode *root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        currentLevel(root, 1);
    }
}
};

Bstnode *Bstnode::insert(Bstnode *temp, int d)
{
  if (temp == NULL)
  {
    Bstnode *newnode = new Bstnode(d);
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

void Bstnode::inorder(Bstnode *temp)
{

  if (temp != NULL)
  {
    inorder(temp->left);
    cout << temp->data << "  ";
    inorder(temp->right);
  }
}

int Bstnode::depth(Bstnode *temp)
{
  if (temp == NULL)
  {
    return 0;
  }
  return (max(
        (depth(temp->left)), (depth(temp->right))) +
      1);
}

void Bstnode::minimum(Bstnode *temp)
{
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  cout << "Minimum value = " << temp->data << endl;
}

void Bstnode::maximum(Bstnode *temp)
{
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  cout << "Maximum value = " << temp->data << endl;
}

void Bstnode::search(Bstnode *temp, int ele)
{
  if (temp != NULL)
  {
    if (temp->data == ele)
    {
      cout << "element found" << endl;
    }
    else if (temp->data > ele)
    {
      search(temp->left, ele);
    }
    else
    {
      search(temp->right, ele);
    }
  }
  else
  {
    cout << "element not found" << endl;
  }
}

void Bstnode::mirror(Bstnode *temp)
{
  if (temp == NULL)
  {
    return;
  }
  else
  {
    Bstnode *ptr;
    mirror(temp->left);
    mirror(temp->right);

    ptr = temp->left;
    temp->left = temp->right;
    temp->right = ptr;
  }
}
int main()
{
  Bstnode n;
  int t;
  cout << "Enter number of elements : ";
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int y;
    cout << "Number = ";
    cin >> y;
    n.root = n.insert(n.root, y);
  }

  int ch = -1;
  while (ch)
  {
    cout << "Enter" << endl;
    cout << "0.Exit" << endl;
    cout << "1.Insert a new node" << endl;
    cout << "2.Find numbers of nodes in longest path" << endl;
    cout << "3.Minimum and maximum data value found in tree" << endl;
    cout << "4.Get mirror image of tree" << endl;
    cout << "5.Search an element" << endl;
    cout << "6.display tree" << endl;
    cout << "Your choice : " << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
      int x;
      cout << "Number = ";
      cin >> x;
      n.root = n.insert(n.root, x);
      break;

    case 2:
      int depth;
      depth = n.depth(n.root);
      cout << "Depth  = ";
      cout << depth << endl;
      break;

    case 3:
      n.minimum(n.root);
      n.maximum(n.root);
      break;

    case 4:
      n.mirror(n.root);
      n.inorder(n.root);
      break;
    case 0:
      break;
    case 5:
      int z;
      cout << "Enter element to be searched : ";
      cin >> z;
      n.search(n.root, z);
      break;

    case 6:
      n.inorder(n.root);
      break;

    default:
      cout << "Enter a valid choice !" << endl;
      break;
    }
  }

  return 0;
}