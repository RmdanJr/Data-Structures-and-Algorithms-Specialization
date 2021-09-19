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

int fibonacci_sum_squares(long long n)
{
    n = n % get_pisano_period(10);

    if (n <= 1)
        return n;
    long long previous = 0, current = 1;
    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
    }
    current = (current + previous) * current;
    return current % 10;
}
int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares(n);
}