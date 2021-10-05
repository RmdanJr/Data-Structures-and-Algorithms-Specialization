#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

int distance(vector<vector<int>> &adj, int s, int t)
{
  vector<int> dist(adj.size(), -1);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    for (int v : adj[u])
      if (dist[v] == -1)
      {
        q.push(v);
        dist[v] = dist[u] + 1;
      }
  }
  return dist[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
