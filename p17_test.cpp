#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findRotationCount(const std::vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid - 1]) {
            return mid;
        } else if (arr[mid] > arr[high]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return 0; // No rotation
}

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Not found
}

int main() {
    vector<int> arr = {9, 13, 16, 18, 19, 23, 28, 31, 37, 42, 1, 3, 4, 5, 7, 8};
    int target = 5;

    int rotationCount = findRotationCount(arr);
    int index = binarySearch(arr, target);

    cout << rotationCount <<"\n";
    cout << index << endl;

    return 0;
}