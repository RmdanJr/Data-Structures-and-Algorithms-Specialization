#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int get_majority_element(vector<int> &a, int left, int right)
{
  sort(a.begin(), a.end());
  int cnt = 1;
  for (int i = 1; i < a.size(); i++)
    if (a[i] == a[i - 1])
    {
      cnt++;
      if (cnt > a.size() / 2)
        return 1;
    }
    else
      cnt = 1;
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
