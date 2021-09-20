#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n)
{
  vector<int> summands;
  //write your code here
  for (int i = 1; n > 0; i++)
  {
    if (n - i == 0 || n - i > i)
    {
      summands.push_back(i);
      n -= i;
    }
  }
  return summands;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i)
  {
    std::cout << summands[i] << ' ';
  }
}
