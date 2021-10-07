#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::pair;
using std::vector;

class UnionFind
{
private:
  vector<int> p, rank;

public:
  UnionFind(int N)
  {
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j)
  {
    if (!isSameSet(i, j))
    {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else
      {
        p[x] = y;
        if (rank[x] == rank[y])
          rank[y]++;
      }
    }
  }
};

double distance(int v1, int v2, vector<int> &x, vector<int> &y)
{
  return sqrt(pow((x[v1] - x[v2]), 2) + pow((y[v1] - y[v2]), 2));
}

bool cmp(pair<pair<int, int>, double> &a, pair<pair<int, int>, double> &b)
{
  return a.second < b.second;
}

double minimum_distance(vector<int> x, vector<int> y)
{
  vector<pair<pair<int, int>, double>> edges;
  for (int i = 0; i < x.size(); i++)
    for (int j = 0; j < x.size(); j++)
      if (i != j)
        edges.push_back({{i, j}, distance(i, j, x, y)});
  sort(edges.begin(), edges.end(), cmp);
  UnionFind membership(x.size());
  vector<pair<pair<int, int>, int>> MST;
  double result = 0;
  for (auto edge : edges)
  {
    if (!membership.isSameSet(edge.first.first, edge.first.second))
    {
      MST.push_back(edge);
      result += edge.second;
      membership.unionSet(edge.first.first, edge.first.second);
    }
  }
  return result;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
