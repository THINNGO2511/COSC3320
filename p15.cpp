#include <iostream>
#include <vector>
using namespace std;

// PSID: 2053907
// Submission ID: 80422225-8d27-445e-b7cb-348258cb99b7 

int countWays(int height, int maxSteps) {
    if (height <= 1) {
        return 1;
    }

    int ways = 0;
    for (int step = 1; step <= maxSteps && step <= height; step++) {
        ways += countWays(height - step, maxSteps);
    }

    return ways;
}

int main() {
    int height, maxSteps;
    cin >> height;
    cin >> maxSteps;

    int result = countWays(height, maxSteps);
    cout << result <<endl;

    return 0;
}
