#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int> > result;//2d vect to contain result
        int n = nums.size();//getting size

        //sort the array (-3,-3,0,1,2,3)
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){// iterate through the array
            //if i at 1, and checks that the number it's at is the same as the last one, it skips, hence "continue", basically this if checks duplicates.
            if(i > 0 & nums[i]==nums[i-1]){
                continue;
            }

            int left = i+1; //next number from i (index)
            int right = n-1;//last number in array (index)
            while( left < right){//as long as they have not met
                int currentSum = nums[i]+nums[left]+nums[right];//a sum to keep track of 3 nums
                if(currentSum == 0){//if found
                    result.push_back({nums[i],nums[left],nums[right]});
                
                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                //move both pointers;
                left++;
                right--;
                //move pointers when requirement is not reached, move left to right when currentSum too small, and vice versa
                } else if (currentSum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    return result;
}




int main() {
    // Example usage
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 0;

    vector<vector<int>> result = threeSum(nums);

    // Display the result
    for (const auto& triplet : result) {
        cout << "[";
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
