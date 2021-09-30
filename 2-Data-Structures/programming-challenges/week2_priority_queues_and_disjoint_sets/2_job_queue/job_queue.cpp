#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using std::cin;
using std::cout;
using std::pair;
using std::priority_queue;
using std::vector;

auto cmp = [](pair<int, long long> a, pair<int, long long> b)
{
  return (a.second == b.second) ? (a.first > b.first) : (a.second > b.second);
};

class JobQueue
{
private:
  int num_workers_;
  vector<int> jobs_;
  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const
  {
    for (int i = 0; i < jobs_.size(); ++i)
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
  }

  void ReadData()
  {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for (int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs()
  {
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> q(cmp);
    for (int i = 0; i < num_workers_; i++)
      q.push({i, 0});
    for (int i = 0; i < jobs_.size(); i++)
    {
      int time = jobs_[i];
      pair<int, long long> p;
      p = q.top();
      q.pop();
      assigned_workers_[i] = p.first;
      start_times_[i] = p.second;
      q.push({p.first, p.second + time});
    }
  }

public:
  void Solve()
  {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
