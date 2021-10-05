#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void explore(vector<vector<int>> &adj, vector<bool> &visited, int x)
{
  for (int i : adj[x])
    if (!visited[i])
    {
      visited[i] = true;
      explore(adj, visited, i);
    }
}

int acyclic(vector<vector<int>> &adj)
{
  int result = 0;
  for (int i = 0; i < adj.size(); i++)
  {
    vector<bool> visited(adj.size(), false);
    explore(adj, visited, i);
    if (visited[i])
    {
      result = 1;
      break;
    }
  }
  return result;
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
