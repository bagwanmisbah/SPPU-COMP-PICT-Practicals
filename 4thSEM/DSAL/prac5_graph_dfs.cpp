#include <iostream>
using namespace std;
#define MAXSIZE 20

class node
{
    int data;
    node *next;

public:
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int val)
    {
        data = val;
        next = NULL;
    }
    friend class graph;
    friend class stack;
    friend class queue;
};

class stack
{
private:
    int data[MAXSIZE];
    int top;

public:
    stack()
    {
        top = -1;
    }
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int element)
    {
        data[++top] = element;
    }
    void pop()
    {
        top--;
    }
    int gettop()
    {
        return data[top];
    }
};
class queue
{
    node *front;
    node *rear;
    int size;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    void push(int no)
    {
        node *newn = new node();
        newn->data = no;
        newn->next = NULL;
        if (front == NULL && rear == NULL) // queue is empty
        {
            front = newn;
            rear = newn;
        }
        else
        {
            rear->next = newn; // attaching the recently created node to the rest of the queue
            rear = newn;       // making the recently created node as new rear
        }
        size++;
    }
    void pop()
    {
        node *temp = front;
        if (front == NULL && rear == NULL)
        {
            cout << "Queue is empty " << endl;
        }
        if (front == rear) // only one element
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            delete temp; // temp stored the current
        }
        size--;
    }
    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int getfront()
    {
        return front->data;
    }
};
class graph
{
    int maxsize;
    node *arr[MAXSIZE];

public:
    graph()
    {
        maxsize = 0;
    }
    graph(int max)
    {
        maxsize = max;
        for (int i = 0; i < maxsize; i++)
        {
            arr[i] = NULL;
        }
    }
    void addedge(int src, int dest)
    {
        node *newn1 = new node();
        newn1->data = src;
        node *newn2 = new node();
        newn2->data = dest;
        node *temp;
        if (arr[src] == NULL)
        {
            arr[src] = newn2;
        }
        else
        {
            temp = arr[src];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn2;
        }
        if (arr[dest] == NULL)
        {
            arr[dest] = newn1;
        }
        else
        {
            temp = arr[src];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn1;
        }
    }
    void display()
    {
        for (int i = 0; i < maxsize; i++)
        {
            cout << "Vertex  " << i << "->";
            node *temp = arr[i];
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void BFS(int src)
    {
        queue q;
        bool visited[maxsize] = {};
        q.push(src);
        visited[src] = 1;
        while (!q.empty())
        {
            src = q.getfront();
            q.pop();
            cout << src << " , ";
            node *temp = arr[src];
            while (temp != NULL)
            {
                if (visited[temp->data] == 0)
                {
                    visited[temp->data] = 1;
                    q.push(temp->data);
                }
                temp = temp->next;
            }
        }
    }
    void DFS(int src)
    {
        stack st;
        bool visited[maxsize] = {};
        st.push(src);
        visited[src] = 1;
        while (!st.isempty())
        {
            src = st.gettop();
            st.pop();
            cout << src << " ,";
            node *temp = arr[src];
            while (temp != NULL)
            {
                if (visited[temp->data] == 0)
                {
                    visited[temp->data] = 1;
                    st.push(temp->data);
                }
                temp = temp->next;
            }
        }
    }
};
int main()
{
    int vertices, v1, v2;
    char choice;

    cout << "Enter number of vertices\n";
    cin >> vertices;
    graph g(vertices);
    do
    {
        cout << "----MENU----\n";
        cout << "1) Add Edge\n";
        cout << "2) Display\n";
        cout << "3) BFS\n";
        cout << "4) DFS\n";
        cout << "5) Exit\n";
        cout << "Enter your choice\n";
        cin >> choice;

        switch (choice)
        {
        case '1':
            cout << "Enter vertex 1 : \n";
            cin >> v1;
            cout << "Enter vertex 2 : \n";
            cin >> v2;
            g.addedge(v1, v2);
            break;
        case '2':
            g.display();
            break;
        case '3':
            g.BFS(0);
            break;
        case '4':
            g.DFS(0);
            break;
        case '5':
            cout << "Thank you\n";
            break;
        default:
            cout << "Choose between (0-5)\n";
        }
    } while (choice != '5');

    return 0;
}
