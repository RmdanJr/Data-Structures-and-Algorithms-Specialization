#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::deque;
using std::vector;

void max_sliding_window_naive(vector<int> const &A, int w)
{
    deque<int> q;
    for (int i = 0; i < A.size(); i++)
    {
        if (!q.empty() && q.front() == i - w)
            q.pop_front();
        while (!q.empty() && A[q.back()] < A[i])
            q.pop_back();
        q.push_back(i);
        if (i + 1 >= w)
            cout << A[q.front()] << " ";
    }
    return;
}

int main()
{
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window_naive(A, w);

    return 0;
}
