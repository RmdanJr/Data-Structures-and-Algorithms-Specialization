#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

int bipartite(vector<vector<int>> &adj)
{
  vector<int> tags(adj.size(), -1);
  queue<int> qu;
  int flag = 0;
  qu.push(0);
  tags[0] = flag;
  while (!qu.empty())
  {
    int u = qu.front();
    qu.pop();
    flag = !flag;
    for (int v : adj[u])
      if (tags[v] == -1)
      {
        qu.push(v);
        tags[v] = flag;
      }
      else if (tags[v] == tags[u])
        return 0;
  }
  return 1;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
