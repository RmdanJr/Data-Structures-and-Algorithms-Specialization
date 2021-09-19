#include <iostream>

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

long long get_fibonacci_huge(long long n, long long m)
{
    long long remainder = n % get_pisano_period(m), previous = 0, current = 1, res = remainder;
    for (int i = 1; i < remainder; i++)
    {
        res = (previous + current) % m;
        previous = current;
        current = res;
    }
    return res % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
