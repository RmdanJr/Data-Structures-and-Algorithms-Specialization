#include <iostream>
#include <vector>

using std::vector;

int get_change(int m)
{
  int dp[m + 1];
  dp[0] = 0;
  for (int i = 1; i <= m; i++)
  {
    dp[i] = __INT_MAX__;
    for (auto coin : vector<int>{1, 3, 4})
    {
      if (i >= coin)
      {
        int numCoins = dp[i - coin] + 1;
        if (numCoins < dp[i])
          dp[i] = numCoins;
      }
    }
  }
  return dp[m];
}

int main()
{
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
