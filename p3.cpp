#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// PSID: 2053907
// Submission ID: e2d1b566-2a4b-4193-ba09-a818358076d6

int ans = INT_MAX;

void solve(const vector<int>& weights, int index, vector<int>& bags) {
    if (index == weights.size()) {
        ans = min(ans, *max_element(bags.begin(), bags.end()));
        return;
    }

    for (int i = 0; i < bags.size(); ++i) {
        bags[i] += weights[index];

        if (bags[i] < ans) // Pruning
            solve(weights, index + 1, bags);

        bags[i] -= weights[index];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) 
        cin >> weights[i];

    sort(weights.rbegin(), weights.rend());  // Sort in descending order

    vector<int> bags(k, 0);
    solve(weights, 0, bags);
    cout << ans;

    return 0;
}
