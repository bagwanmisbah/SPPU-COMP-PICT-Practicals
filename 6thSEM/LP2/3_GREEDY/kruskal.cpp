#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Edge structure
struct Edge
{
  int u, v, weight;
};

// Sort by ascending weight
bool compare(Edge a, Edge b)
{
  return a.weight < b.weight;
}

// Disjoint Set (Union-Find)
vector<int> parent;

int find(int x)
{
  if (parent[x] != x)
    parent[x] = find(parent[x]); // Path compression
  return parent[x];
}

void unite(int a, int b)
{
  int rootA = find(a);
  int rootB = find(b);
  if (rootA != rootB)
    parent[rootB] = rootA;
}

int main()
{
  int V, E;
  cout << "Enter number of vertices and edges: ";
  cin >> V >> E;

  vector<Edge> edges;
  cout << "Enter edges (u v weight):\n";
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  // Initialize each node as its own parent
  parent.resize(V + 1); // now parent[1] safe
  for (int i = 1; i <= V; i++)
    parent[i] = i;

  // Sort edges by weight
  sort(edges.begin(), edges.end(), compare);

  int mstWeight = 0;
  cout << "\nEdges in MST:\n";
  for (Edge e : edges)
  {
    if (find(e.u) != find(e.v))
    {
      unite(e.u, e.v);
      mstWeight += e.weight;
      cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }
  }

  cout << "Total weight of MST: " << mstWeight << endl;
  return 0;
}
// ip
// 7 9

// 1 4 1
// 1 2 2
// 2 3 3
// 2 4 3
// 1 5 4
// 3 4 5
// 2 6 7
// 3 6 8
// 4 5 9

// int mstWeight = 0;
// cout << "\nEdges in MST:\n";

// for (Edge e : edges)
// {
//   if (find(e.u) != find(e.v))
//   {                                                           // Check if u and v are in different sets
//     unite(e.u, e.v);                                          // Join the sets
//     mstWeight += e.weight;                                    // Add this edge’s weight to total
//     cout << e.u << " - " << e.v << " : " << e.weight << endl; // Print the edge
//   }
// }
