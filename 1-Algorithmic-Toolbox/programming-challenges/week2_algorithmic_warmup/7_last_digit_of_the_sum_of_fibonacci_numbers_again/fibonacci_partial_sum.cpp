#include <iostream>
#include <vector>
using std::vector;

long long get_pisano_period(long long m)
{
    long long a = 0, b = 1, c = a + b;
    for (long long i = 0; i < m * m; i++)
    {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1)
            return i + 1;
    }
}

int sum(long long n)
{
    n = n % get_pisano_period(10);
    if (n <= 1)
        return n;
    long long previous = 0;
    long long current = 1;
    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }
    return current % 10;
}

long long get_fibonacci_partial_sum(long long from, long long to)
{
    long long s = sum(to + 2) - 1;
    long long t = sum(from + 1) - 1;
    return (s - t + 10) % 10;
}

int main()
{
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
