#include <iostream>
#include <vector>
#include <algorithm>

using std::min;
using std::vector;

vector<int> optimal_sequence(int n)
{
  std::vector<int> sequence;
  int dp[n + 1];
  dp[0] = 0;
  for (int i = 1; i <= n; i++)
  {
    dp[i] = dp[i - 1] + 1;
    if (i % 2 == 0)
      dp[i] = min(1 + dp[i / 2], dp[i]);
    if (i % 3 == 0)
      dp[i] = min(1 + dp[i / 3], dp[i]);
  }
  for (int i = n; i > 1;)
  {
    sequence.push_back(i);
    if (dp[i - 1] == dp[i] - 1)
      i = i - 1;
    else if (i % 2 == 0 && (dp[i / 2] == dp[i] - 1))
      i = i / 2;
    else if (i % 3 == 0 && (dp[i / 3] == dp[i] - 1))
      i = i / 3;
  }
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
