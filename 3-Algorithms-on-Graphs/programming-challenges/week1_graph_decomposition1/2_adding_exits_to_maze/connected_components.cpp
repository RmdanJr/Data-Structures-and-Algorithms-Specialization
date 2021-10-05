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

int number_of_components(vector<vector<int>> &adj)
{
  int count = 0;
  vector<bool> visited(adj.size(), false);
  for (int v = 0; v < adj.size(); v++)
    if (!visited[v])
    {
      dfs(adj, visited, v);
      count++;
    }
  return count;
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
  std::cout << number_of_components(adj);
}
