#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n; // Input the length of the array
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; // Input the elements of the array
    }

    int max_diff = 0; // Initialize the maximum difference to 0
    int min_element = arr[0]; // Initialize the minimum element found so far

    for (int i = 1; i < n; i++) {
        max_diff = max(max_diff, arr[i] - min_element); // Update max_diff if a larger difference is found
        min_element = min(min_element, arr[i]); // Update min_element if a smaller element is found
    }

    if (max_diff < 0) {
        cout << "0" << endl;
    } else {
        cout << max_diff << endl;
    }

    return 0;
}