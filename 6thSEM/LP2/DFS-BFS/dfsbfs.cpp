#include <bits/stdc++.h>
using namespace std;

void bfs_traversal(int start, vector<vector<int>> adj)
{
  int n = adj.size();
  // vector<int> visited(n, 0);
  int visited[n + 1] = {0};
  queue<int> q;
  // q.push(1);
  // visited[1] = 1;

  q.push(start);
  visited[start] = 1;
  vector<int> bfs;
  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for (auto neighbour : adj[node])
    {
      if (!visited[neighbour])
      {
        visited[neighbour] = 1;
        q.push(neighbour);
      }
    }
  }
  cout << "BFS traversal: ";
  for (auto it : bfs)
  {
    cout << it << " ";
  }
}
void dfs_traversal(int start, vector<vector<int>> adj)
{
  vector<int> dfs;
  stack<int> st;
  int n = adj.size();
  int visited[n + 1] = {0};
  // st.push(1);
  // visited[1] = 1;
  st.push(start);
  visited[start] = 1;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    dfs.push_back(node);
    for (auto neighbour : adj[node])
    {
      if (!visited[neighbour])
      {
        visited[neighbour] = 1;
        st.push(neighbour);
      }
    }
  }
  cout << "DFS traversal: ";
  for (auto it : dfs)
  {
    cout << it << " ";
  }
}
int main()
{
  int flag = true;
  int choice;
  vector<vector<int>> adj;

  while (flag == true)
  {
    cout << endl;
    cout << "DFS-BFS TRAVERSAL: " << endl;
    cout << "--------------------------------" << endl;
    cout << "1.Create Graph " << endl;
    cout << "2.Print Graph " << endl;
    cout << "3.BFS Traversal" << endl;
    cout << "4.DFS Traversal" << endl;
    cout << "5.Exit" << endl;
    cout << "--------------------------------" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cout << "--------------------------------" << endl;
    switch (choice)
    {
    case 1:
    {
      int n, m;
      cout << "Creating Graph" << endl;
      cout << "Enter number of nodes: ";
      cin >> n;
      cout << endl;
      cout << "Enter number of edges: ";
      cin >> m;
      adj.clear();
      adj.resize(n + 1);
      for (int i = 0; i < m; i++)
      {
        int u, v;
        cout << "Enter starting vertex: ";
        cin >> u;
        cout << endl;
        cout << "Enter end vertex: ";
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      for (auto &neighbours : adj)
      {
        sort(neighbours.begin(), neighbours.end());
      }
      break;
    }
    case 2:
    {
      int n = adj.size();
      for (int i = 1; i < n; i++)
      {
        cout << i << " : ";
        for (auto neighbour : adj[i])
        {
          cout << neighbour << " ";
        }
        cout << endl;
      }
      break;
    }
    case 3:
    {
      int start;
      cout << "Enter starting node for BFS Traversal: ";
      cin >> start;
      bfs_traversal(start, adj);
      break;
    }
    case 4:
    {
      int start;
      cout << "Enter starting node for DFS Traversal: ";
      cin >> start;
      dfs_traversal(start, adj);
      break;
    }
    case 5:
    {
      flag = false;
      break;
    }
    }
  }
}