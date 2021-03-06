#include <iostream>
#include <vector>

using std::pair;
using std::vector;

void dfs(vector<vector<int>> &adj, vector<bool> &visited, int v)
{
  visited[v] = true;
  for (int u : adj[v])
    if (!visited[u])
      dfs(adj, visited, u);
}

int reach(vector<vector<int>> &adj, int x, int y)
{
  vector<bool> visited(adj.size(), false);
  dfs(adj, visited, x);
  if (visited[y])
    return 1;
  return 0;
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
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;
  std::cout << reach(adj, x - 1, y - 1);
}
