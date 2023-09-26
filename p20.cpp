#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void generateSteppingNumbers(int current, int low, int high, vector<int>& result) {
    if (current >= low && current <= high) {
        result.push_back(current);
    }
    
    if (current == 0 || current > high) {
        return;
    }

    int lastDigit = current % 10;
    int nextLow = current * 10 + lastDigit - 1;
    int nextHigh = current * 10 + lastDigit + 1;

    if (lastDigit == 0) {
        generateSteppingNumbers(nextHigh, low, high, result);
    }
    else if (lastDigit == 9) {
        generateSteppingNumbers(nextLow, low, high, result);
    }
    else {
        generateSteppingNumbers(nextLow, low, high, result);
        generateSteppingNumbers(nextHigh, low, high, result);
    }
}

vector<int> findSteppingNumbers(int low, int high) {
    vector<int> result;

    for (int i = 0; i <= 9; ++i) {
        generateSteppingNumbers(i, low, high, result);
    }

    sort(result.begin(), result.end());
    return result;
}

int main() {
    int low, high;
    cin >> low >> high;

    vector<int> steppingNumbers = findSteppingNumbers(low, high);

    for (int num : steppingNumbers) {
        cout << num << " ";
    }
    
    cout << endl;

    return 0;
}
