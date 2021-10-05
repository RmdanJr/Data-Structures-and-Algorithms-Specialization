#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::pair;
using std::vector;

void dfs(vector<vector<int>> &adj, int x, vector<bool> &visited, std::stack<int> &stack)
{
  visited[x] = true;
  for (int u : adj[x])
    if (!visited[u])
    {
      visited[u] = true;
      dfs(adj, u, visited, stack);
    }
  stack.push(x);
}

vector<vector<int>> reverseEdges(vector<vector<int>> &adj)
{
  vector<vector<int>> reversedAdj(adj.size(), vector<int>());
  for (int i = 0; i < adj.size(); i++)
    for (int j = 0; j < adj[i].size(); j++)
      reversedAdj[adj[i][j]].push_back(i);
  return reversedAdj;
}

int number_of_strongly_connected_components(vector<vector<int>> adj)
{
  int result = 0;
  std::stack<int> stack;
  vector<bool> visited(adj.size(), false);
  vector<vector<int>> reversedAdj = reverseEdges(adj);
  for (int i = 0; i < adj.size(); i++)
    if (!visited[i])
      dfs(adj, i, visited, stack);
  std::fill(visited.begin(), visited.end(), false);
  std::stack<int> stk;
  while (!stack.empty())
  {
    int x = stack.top();
    stack.pop();
    if (!visited[x])
    {
      dfs(reversedAdj, x, visited, stk);
      result += 1;
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
  std::cout << number_of_strongly_connected_components(adj);
}
