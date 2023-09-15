#include <iostream>
#include <vector>

using namespace std;

//8ae462e3-da5d-4c84-9047-15c4bcc84c90 
int main() {
    int n;
    cin >> n; 
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

    int max_diff = 0;
    int min_element = arr[0]; 
    for (int i = 1; i < n; i++) {
        max_diff = max(max_diff, arr[i] - min_element); 
        min_element = min(min_element, arr[i]); 
    }

    if (max_diff < 0) {
        cout << "0" << endl;
    } else {
        cout << max_diff << endl;
    }

    return 0;
}