#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

// PSID: 2053907
// Submission ID: 64fc2807-6d66-4c80-955c-84158599fca9

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();

    // Create a vector of triplets (end time, start time, profit) for easy sorting
    vector<tuple<int, int, int>> jobs;
    for (int i = 0; i < n; ++i) {
        jobs.push_back({endTime[i], startTime[i], profit[i]});
    }

    // Sort the jobs based on their end times
    sort(jobs.begin(), jobs.end());

    // dp[i] stores the maximum profit for jobs up to index i
    vector<int> dp(n, 0);
    dp[0] = get<2>(jobs[0]);  // Initialize with the profit of the first job

    for (int i = 1; i < n; ++i) {
        // Include the current job
        int includedProfit = get<2>(jobs[i]);
        int nonOverlappingJobIndex = -1;

        // Find the latest job that doesn't overlap with the current job
        for (int j = i - 1; j >= 0; --j) {
            if (get<0>(jobs[j]) <= get<1>(jobs[i])) {
                nonOverlappingJobIndex = j;
                break;
            }
        }

        if (nonOverlappingJobIndex != -1) {
            includedProfit += dp[nonOverlappingJobIndex];
        }

        // Exclude the current job
        int excludedProfit = dp[i - 1];

        // Store the maximum profit
        dp[i] = max(includedProfit, excludedProfit);
    }

    return dp[n - 1];

}

int main(){
    vector<int> startTime, endTime, profit;
    string inStart, inEnd, inProfit;

    getline(cin, inStart);
    getline(cin, inEnd);
    getline(cin, inProfit);

    stringstream x(inStart), y(inEnd), z(inProfit);

    int i;

    while(x >> i){
        startTime.push_back(i);
    };

    while(y >> i){
        endTime.push_back(i);
    };

    while(z >> i){
        profit.push_back(i);
    };

    cout<<jobScheduling(startTime, endTime, profit);

    return 0;
}

