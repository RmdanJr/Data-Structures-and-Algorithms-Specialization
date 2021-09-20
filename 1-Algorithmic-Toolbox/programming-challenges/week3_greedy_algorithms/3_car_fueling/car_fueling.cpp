#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::vector;

int compute_min_refills(int dist, int tank, vector<int> &stops)
{
    stops.resize(stops.size() + 2);
    for (int i = stops.size() - 2; i > 0; i--)
        stops[i] = stops[i - 1];
    stops[0] = 0;
    stops[stops.size() - 1] = dist;
    int numRefills = 0, currentRefill = 0;
    while (currentRefill < stops.size() - 1)
    {
        int lastRefill = currentRefill;
        while (currentRefill < stops.size() - 1 && stops[currentRefill + 1] - stops[lastRefill] <= tank)
            currentRefill += 1;
        if (currentRefill == lastRefill)
            return -1;
        if (currentRefill <= stops.size() - 1)
            numRefills += 1;
    }
    return numRefills - 1;
}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
