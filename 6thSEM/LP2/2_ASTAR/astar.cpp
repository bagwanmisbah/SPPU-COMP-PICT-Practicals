#include <bits/stdc++.h>
using namespace std;

int main()
{

  cout << "Enter number of nodes and edges: " << endl;
  int n, e, u, v, w;
  cin >> n >> e;

  vector<pair<int, int>> graph[n];
  cout << "Enter u v weight: " << endl;
  for (int i = 0; i < e; i++)
  {
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
    // graph[v].push_back({u, w}); // undirected
  }
  cout << "Enter heuristic value for all nodes: " << endl;
  vector<int> h(n);
  for (int i = 0; i < n; i++)
  {
    cin >> h[i]; // heuristic value for each node
  }

  int start, goal;
  cout << "Enter start and goal node: " << endl;
  cin >> start >> goal;

  vector<int> f(n, INT_MAX), g(n, INT_MAX), parent(n, -1);
  vector<bool> visited(n, false);

  g[start] = 0;
  f[start] = g[start] + h[start];

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({f[start], start});

  while (!pq.empty())
  {
    int node = pq.top().second;
    pq.pop();

    if (visited[node])
      continue;
    visited[node] = true;

    if (node == goal)
      break;

    for (auto i : graph[node])
    {
      int child = i.first;
      int weight = i.second;

      if (!visited[child] && g[node] + weight + h[child] < f[child])
      {
        g[child] = g[node] + weight;
        f[child] = g[child] + h[child];
        pq.push({f[child], child});
        parent[child] = node;
      }
    }
  }

  if (g[goal] == INT_MAX)
  {
    cout << "No path found." << endl;
    return 0;
  }

  vector<int> path;
  for (int at = goal; at != -1; at = parent[at])
  {
    path.push_back(at);
  }
  reverse(path.begin(), path.end());

  cout << "Path is [ ";
  for (int c : path)
    cout << c << " ";
  cout << "]" << endl;
  cout << "Total Cost: " << g[goal] << endl;

  return 0;
}
// Enter number of nodes and edges:
// 7 9
// Enter u v weight:
// 0 1 1
// 0 2 4
// 1 2 2
// 1 3 3
// 2 4 5
// 3 5 2
// 4 6 3
// 3 6 4
// 5 6 1
// Enter heuristic value for all nodes:
// 5
// 6
// 4
// 3
// 3
// 1
// 0
// Enter start and goal node:
// 0
// 6
