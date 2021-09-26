#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
  vector<vector<int>> val(W + 1, vector<int>(w.size() + 1));
  for (int i = 0; i <= w.size(); i++)
    for (int j = 0; j <= W; j++)
      if (i == 0 || j == 0)
        val[j][i] = 0;
      else
      {
        val[j][i] = val[j][i - 1];
        if (w[i - 1] <= j)
        {
          int value = val[j - w[i - 1]][i - 1] + w[i - 1];
          if (value > val[j][i])
            val[j][i] = value;
        }
      }
  return val[W][w.size()];
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++)
  {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
