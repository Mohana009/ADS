// job sequences
//------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int len = deadline.size();
        vector<pair<int,int>> v(len);
        int maxdeadline = deadline[0];

        for(int i = 0; i < len; i++) {
            v[i] = {profit[i], deadline[i]}; // pairing the profit and deadline
            maxdeadline = max(maxdeadline, deadline[i]); // find the max dead line
        }

        sort(v.begin(), v.end()); // sort based on profit in ascending order
        vector<int> job(maxdeadline + 1, -1);

        int totalJobs = 0, totalProfit = 0;
        
        // after sorting last ele has max profit
        for(int i = len - 1; i >= 0; i--) {
            for(int j = v[i].second; j >= 0; j--) {
            	// done the most profit job 1st
                if(job[j] == -1) {
                    job[j] = 0;
                    totalJobs++;
                    totalProfit += v[i].first;
                    break;
                }
            }
        }
        
        return {totalJobs, totalProfit};
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<int> deadline(n), profit(n);
    cout << "Enter deadlines: ";
    for(int i = 0; i < n; i++)
        cin >> deadline[i];

    cout << "Enter profits: ";
    for(int i = 0; i < n; i++)
        cin >> profit[i];

    vector<int> ans = obj.jobSequencing(deadline, profit);

    cout << "Maximum jobs done: " << ans[0] << endl;
    cout << "Total profit earned: " << ans[1] << endl;

    return 0;
}