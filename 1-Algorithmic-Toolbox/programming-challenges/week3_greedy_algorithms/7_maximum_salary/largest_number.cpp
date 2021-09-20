#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::string;
using std::vector;

bool cmp(string &a, string &b)
{
  return a + b < b + a;
}

string largest_number(vector<string> a)
{
  //write your code here
  string result = "";
  while (!a.empty())
  {
    auto maxDigitIt = std::max_element(a.begin(), a.end(), cmp);
    result += *maxDigitIt;
    a.erase(maxDigitIt);
  }
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
