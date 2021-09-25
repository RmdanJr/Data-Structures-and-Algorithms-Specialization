#include <bits/stdc++.h>

using namespace std;

int bin_search(vector<int> &a, int x)
{
  int left = 0, right = a.size() - 1;
  if (x > a[right])
    return right + 1;
  if (x < a[left])
    return left;
  while (left < right)
  {
    int mid = left + (right - left) / 2;
    if (x >= a[mid] && x < a[mid + 1])
      return mid + 1;
    if (x >= a[mid])
      left = mid;
    else
      right = mid;
  }
  return -1;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  //write your code here
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  int i = 0;
  for (auto p : points)
  {
    int s = bin_search(starts, p);
    int e = bin_search(ends, p);
    cnt[i++] = s - e;
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++)
  {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
}
