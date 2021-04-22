#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Data structure to store a Job
struct Job {
    int start, finish, profit;
};
 
// Function to perform a binary search on the given jobs, which are
// sorted by finish time. The function returns the index of the last job, which
// doesn't conflict with the given job, i.e., whose finish time is
// less than or equal to the given job's start time.
int findLastNonConflictingJob(vector<Job> const &jobs, int n)
{
    // search space
    int low = 0;
    int high = n;
 
    // iterate till the search space is exhausted
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (jobs[mid].finish <= jobs[n].start)
        {
            if (jobs[mid + 1].finish <= jobs[n].start) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        else {
            high = mid - 1;
        }
    }
 
    // return the negative index if no non-conflicting job is found
    return -1;
}
 
// Function to find the maximum profit of non-overlapping jobs using DP
int findMaxProfit(vector<Job> jobs)        // no-ref, no-const
{
    // sort jobs in increasing order of their finish times
    sort(jobs.begin(),
        jobs.end(),
        [](Job &x, Job &y) {
            return x.finish < y.finish;
        });
 
    // get the number of jobs
    int n = jobs.size();
 
    // construct a lookup table where the i'th index stores the maximum profit
    // for the first `i` jobs
    int maxProfit[n];
 
    // maximum profit gained by including the first job
    maxProfit[0] = jobs[0].profit;
 
    // fill the `maxProfit[]` table in a bottom-up manner from the second index
    for (int i = 1; i < n; i++)
    {
        // find the index of the last non-conflicting job with the current job
        int index = findLastNonConflictingJob(jobs, i);
 
        // include the current job with its non-conflicting jobs
        int incl = jobs[i].profit;
        if (index != -1) {
            incl += maxProfit[index];
        }
 
        // store the maximum profit by including or excluding the current job
        maxProfit[i] = max(incl, maxProfit[i-1]);
    }
 
    // return maximum profit
    return maxProfit[n-1];
}
 
int main()
{
    vector<Job> jobs {
        { 0, 6, 60 },
        { 1, 4, 30 },
        { 3, 5, 10 },
        { 5, 7, 30 },
        { 5, 9, 50 },
        { 7, 8, 10 }
    };
 
    cout << "The maximum profit is " << findMaxProfit(jobs);
 
    return 0;
}


