#include <bits/stdc++.h>
using namespace std;

struct Job
{
  int id, deadline, profit;
};

bool compare(Job a, Job b)
{
  return a.profit > b.profit;
}

void job_scheduling(vector<Job> &jobs)
{
  sort(jobs.begin(), jobs.end(), compare);
  int n = jobs.size();

  int maxdeadline = 0;
  for (auto job : jobs)
  {
    maxdeadline = max(maxdeadline, job.deadline);
  }

  vector<int> slot(maxdeadline + 1, -1);
  int totalprofit = 0;

  cout << "Scheduled job ids: ";
  for (auto job : jobs)
  {
    for (int t = job.deadline; t > 0; t--)
    {
      if (slot[t] == -1)
      {
        slot[t] = job.id;
        totalprofit += job.profit;
        cout << job.id << " ";
        break;
      }
    }
  }
  cout << "Total profit: " << totalprofit << endl;
}

int main()
{
  int n;
  cout << "Enter number of jobs: ";
  cin >> n;

  vector<Job> jobs;
  cout << "Enter job info ( job deadline and job profit) for each job \n";
  for (int i = 0; i < n; i++)
  {
    int d, p;
    cin >> p >> d;
    jobs.push_back({i + 1, d, p});
  }
  job_scheduling(jobs);
  return 0;
}