#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const vector<long long> &numbers)
{
    return numbers[numbers.size() - 1] * numbers[numbers.size() - 2];
}

int main()
{
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];
    sort(numbers.begin(), numbers.end());
    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
