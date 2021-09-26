#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <string.h>

using std::max;
using std::min;
using std::string;
using std::vector;

long long eval(long long a, long long b, char op)
{
  if (op == '*')
  {
    return a * b;
  }
  else if (op == '+')
  {
    return a + b;
  }
  else if (op == '-')
  {
    return a - b;
  }
  else
  {
    assert(0);
  }
}

long long get_maximum_value(const string &exp)
{
  int len = exp.length() / 2 + 1;
  long long d[exp.length() / 2 + 1];
  char op[exp.length() / 2];
  int n = exp.length();
  char char_array[n + 1];
  strcpy(char_array, exp.c_str());
  int x = 0;
  for (int i = 0; i < n; i += 2)
  {
    d[x] = (long long)char_array[i] - 48;
    x++;
  }
  x = 0;
  for (int i = 1; i < n; i += 2)
  {
    op[x] = char_array[i];
    x++;
  }
  long long m[len][len];
  long long M[len][len];
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len; j++)
    {
      m[i][j] = 0;
      M[i][j] = 0;
    }
  for (int i = 0; i < len; i++)
  {
    m[i][i] = d[i];
    M[i][i] = d[i];
  }
  for (int s = 1; s < len; s++)
  {
    for (int i = 0; i < len - s; i++)
    {
      int j = i + s;
      long long mn = __LONG_LONG_MAX__;
      long long mx = __LONG_LONG_MAX__ + 1;
      for (int k = i; k < j; k++)
      {
        long long a = eval(M[i][k], M[k + 1][j], op[k]);
        long long b = eval(M[i][k], m[k + 1][j], op[k]);
        long long c = eval(m[i][k], m[k + 1][j], op[k]);
        long long d = eval(m[i][k], M[k + 1][j], op[k]);
        mn = min(mn, min(a, min(b, min(c, d))));
        mx = max(mx, max(a, max(b, max(c, d))));
      }
      m[i][j] = mn;
      M[i][j] = mx;
    }
  }
  return M[0][len - 1];
}

int main()
{
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
