#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

bool compare(char a, char b) { return a > b; }

// Function to find the highest possible number with at most K swaps
void findMaximumNum(string str, int k, string& max, int ctr) {
    // Return if no swaps left
    if (k == 0) return;

    int n = str.length();
    char maxm = str[ctr];

    for (int j = ctr + 1; j < n; j++) {
        // Find the maximum digit greater than at ctr among the rest
        if (maxm < str[j])
            maxm = str[j];
    }

    if (maxm != str[ctr])
        --k;

    for (int j = n - 1; j >= ctr; j--) {
        if (str[j] == maxm) {
            swap(str[ctr], str[j]);

            if (str.compare(max) > 0)
                max = str;

            findMaximumNum(str, k, max, ctr + 1);

            swap(str[ctr], str[j]);
        }
    }
}


void minSwaps(string& initial, const string& max_possible, int& minNumSwaps, int swaps = 0, int idx = 0) {
    if (initial == max_possible) {
        minNumSwaps = min(minNumSwaps, swaps);
        return;
    }
    char maxDigit = '0';
    for (int i = idx; i < initial.size(); i++) { maxDigit = max(maxDigit, initial[i]); }
    if (initial[idx] != maxDigit) { swaps++; }
    for (int i = idx; i < initial.size(); i++) {
        if (initial[i] == maxDigit) {
            swap(initial[i], initial[idx]);
            minSwaps(initial, max_possible, minNumSwaps, swaps, idx + 1);
            swap(initial[i], initial[idx]);
        }
    }
}

int main() {
    string num;
    int k;
    cin >> num;
    cin >> k;

    string max = num;
    findMaximumNum(num, k, max, 0);
    cout << max << endl;

    int minNumSwaps = INT_MAX;
    string numMax = num;
    sort(numMax.begin(), numMax.end(), compare);

    minSwaps(num, numMax, minNumSwaps);
    cout << minNumSwaps << endl;

    return 0;
}
