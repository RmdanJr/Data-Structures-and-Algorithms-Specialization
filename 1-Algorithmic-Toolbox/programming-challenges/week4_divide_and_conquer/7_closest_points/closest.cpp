#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::min;
using std::pair;
using std::sort;
using std::string;
using std::vector;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
  return a.first - a.second >= b.first - b.second;
}

double minimal_distance(vector<int> x, vector<int> y)
{
  //write your code here
  vector<pair<int, int>> vi;
  for (int i = 0; i < x.size(); i++)
    vi.push_back({x[i], y[i]});
  sort(vi.begin(), vi.end(), cmp);
  double distance = MAXFLOAT;
  for (int i = 1; i < vi.size(); i++)
    distance = min(distance, sqrt(pow(vi[i].first - vi[i - 1].first, 2) + pow(vi[i].second - vi[i - 1].second, 2)));
  return distance;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++)
  {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
