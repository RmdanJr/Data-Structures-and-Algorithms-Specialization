#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
  double value = 0.0;
  int n = weights.size();
  vector<pair<double, int>> wv(n);
  for (int i = 0; i < n; i++)
  {
    wv[i] = {(double)values[i] / (double)weights[i], weights[i]};
  }
  sort(wv.rbegin(), wv.rend());
  for (int i = 0; i < n; i++)
  {
    if (capacity == 0)
      return value;
    int a = min(wv[i].second, capacity);
    value += a * wv[i].first;
    wv[i].second -= a;
    capacity -= a;
  }
  return value;
}

int main()
{
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i] >> weights[i];
  }
  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}
