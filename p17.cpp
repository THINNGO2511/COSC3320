#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the rotation count (k) in the rotated sorted array
int findRotationCount(const vector<int>& nums, int left, int right) {
    if (left == right) {
        return left;
    }
    
    int mid = left + (right - left) / 2;
    
    if (mid < right && nums[mid] > nums[mid + 1]) {
        return mid + 1;
    }
    
    if (mid > left && nums[mid] < nums[mid - 1]) {
        return mid;
    }
    
    if (nums[left] < nums[mid]) {
        return findRotationCount(nums, mid + 1, right);
    }
    
    return findRotationCount(nums, left, mid - 1);
}

// Function to perform binary search to find an element in the rotated sorted array
int search(const vector<int>& nums, int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    if (nums[mid] == target) {
        return mid;
    }
    
    if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && target < nums[mid]) {
            return search(nums, target, left, mid - 1);
        } else {
            return search(nums, target, mid + 1, right);
        }
    } else {
        if (nums[mid] < target && target <= nums[right]) {
            return search(nums, target, mid + 1, right);
        } else {
            return search(nums, target, left, mid - 1);
        }
    }
}

int main() {
    vector<int> nums;
    int n, target;
    char c;
    
    // Read input array
    while (cin >> n) {
        nums.push_back(n);
        cin.get(c); // Read space or newline
        if (c == '\n') {
            break;
        }
    }
    
    // Read target value
    cin >> target;
    
    // Find the rotation count (k)
    int k = findRotationCount(nums, 0, nums.size() - 1);
    
    // Output the rotation count (k) as the answer for part (a)
    cout << k<<"\n";
    
    // Perform binary search to find the target value and output the result for part (b)
    int result = search(nums, target, 0, nums.size() - 1);
    cout << result <<"\n";
    
    return 0;
}