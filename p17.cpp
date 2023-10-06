#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

// PSID: 2053907
// Submission ID: a227330b-335e-4075-b4c5-f689c544eaf4 

//function to find the rotation
int findRotationCount(const std::vector<int>& vec) {
    int left = 0;
    int right = vec.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (vec[left] <= vec[mid] && vec[mid] <= vec[right]) {
            return left; 
        }

        if (vec[left] > vec[mid] && vec[mid] <= vec[right]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;  
}

//function to find target number
int binarySearch(const std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
}

int main() {
    vector<int> nums;
    int n = 0, target = 0, result = 0;
    string strInput; 
    stringstream ss(strInput);
    
    // Read input
    getline(cin, strInput);
    ss<<strInput;
    while(ss >> n){
        nums.push_back(n);
    }
    
    // Read target value
    cin >> target;
    
    // Find the rotation count 
    int k = findRotationCount(nums);
    cout << k<<"\n";
    
    // Perform binary search to find the target number 
    result = binarySearch(nums, target);
    cout << result <<"\n";

    return 0;
}