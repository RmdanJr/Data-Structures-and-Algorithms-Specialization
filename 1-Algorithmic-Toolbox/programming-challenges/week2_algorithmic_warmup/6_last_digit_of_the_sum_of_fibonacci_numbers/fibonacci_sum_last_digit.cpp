#include <iostream>

int fibonacci_sum(long long n)
{
    long long fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i - 1] % 10 + fib[i - 2] % 10) % 10;
        ans = (ans + fib[i]) % 10;
    }
    if(n == 0) return 0;
    return ans % 10;
}

int main()
{
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum(n);
}
