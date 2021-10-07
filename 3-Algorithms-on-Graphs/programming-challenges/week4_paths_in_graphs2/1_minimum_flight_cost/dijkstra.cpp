#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;

long long distance(vector<vector<int>> &adj, vector<vector<int>> &cost, int s, int t)
{
  vector<int> dist(adj.size(), std::numeric_limits<int>::max());
  priority_queue<int> pq;
  dist[s] = 0;
  pq.push(s);
  while (!pq.empty())
  {
    int u = pq.top();
    pq.pop();
    for (int v_index = 0; v_index < adj[u].size(); v_index++)
    {
      int v = adj[u][v_index];
      if (dist[v] > dist[u] + cost[u][v_index])
      {
        dist[v] = dist[u] + cost[u][v_index];
        pq.push(v);
      }
    }
  }
  return dist[t] == std::numeric_limits<int>::max() ? -1 : dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
