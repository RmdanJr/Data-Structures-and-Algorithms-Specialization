#include <iostream>
#include <vector>

using std::vector;

int negative_cycle(vector<vector<int>> &adj, vector<vector<int>> &cost)
{
  vector<int> dist(adj.size(), -1), prev(adj.size(), -1), dist_v, dist_vM1;
  dist[0] = 0;
  for (int i = 0; i < adj.size(); i++)
  {
    for (int j = 0; j < adj.size(); j++)
    {
      int ind = 0;
      for (int k : adj[j])
      {
        if (dist[k] > dist[j] + cost[j][ind])
        {
          dist[k] = dist[j] + cost[j][ind];
          prev[k] = j;
        }
        ind++;
      }
    }
    if (i == adj.size() - 2)
      dist_vM1 = dist;
    if (i == adj.size() - 1)
      dist_v = dist;
  }
  return dist_v == dist_vM1 ? 0 : 1;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  vector<vector<int>> cost(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
