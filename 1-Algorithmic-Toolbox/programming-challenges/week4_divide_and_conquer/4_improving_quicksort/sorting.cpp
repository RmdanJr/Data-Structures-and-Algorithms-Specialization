#include <bits/stdc++.h>

using namespace std;

pair<int, int> partition3(vector<int> &a, int l, int r)
{
  int x = a[l], j = l, t = r, i = j;
  while (i <= t)
  {
    if (a[i] < x)
    {
      swap(a[i], a[j]);
      j++;
    }
    else if (a[i] > x)
    {
      swap(a[i], a[t]);
      t--;
      i--;
    }
    i++;
  }
  return {j, t};
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
  if (l >= r)
    return;
  int k = rand() % (r - l + 1) + l;
  swap(a[l], a[k]);
  pair<int, int> p = partition3(a, l, r);
  randomized_quick_sort(a, l, p.first - 1);
  randomized_quick_sort(a, p.second + 1, r);
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
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cout << a[i] << ' ';
  }
}
