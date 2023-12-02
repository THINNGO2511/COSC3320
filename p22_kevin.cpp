////////////////////////// WITHOUT MEMO
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// void backTrack(string num, string &ans, int kSwaps, int counter)
// {
//     if (kSwaps == 0)
//         return;
//     char max = num[counter];
//     for (int i = counter + 1; i < num.length(); i++)
//     {
//         if (num[i] > max)
//         {
//             max = num[i];
//         }
//     }
//     if (max != num[counter])
//     {
//         kSwaps--;
//     }
//     for (int j = num.length() - 1; j >= counter; j--)
//     {
//         if (num[j] == max)
//         {
//             swap(num[j], num[counter]);
//             if (num.compare(ans) > 0)
//             {
//                 ans = num;
//             }
//             backTrack(num, ans, kSwaps, counter + 1);
//             swap(num[j], num[counter]);
//         }
//     }
// }
// void minSwaps(string &num, string maxNum, int swaps, int &minKSwaps, int counter)
// {
//     if (counter == num.length())
//     {
//         if (num == maxNum)
//         {
//             minKSwaps = min(minKSwaps, swaps);
//         }
//         return;
//     }

//     if (swaps >= minKSwaps) // If we have already used more swaps than the current minimum, return early.
//         return;

//     if (num[counter] != maxNum[counter])
//     {
//         // Try to swap the current digit with a larger digit from maxNum.
//         for (int i = counter + 1; i < num.length(); i++)
//         {
//             if (num[i] == maxNum[counter])
//             {
//                 swap(num[i], num[counter]);
//                 minSwaps(num, maxNum, swaps + 1, minKSwaps, counter + 1);
//                 swap(num[i], num[counter]); // Backtrack
//             }
//         }
//     }
//     else
//     {
//         // If the digits are already the same, no swap is needed.
//         minSwaps(num, maxNum, swaps, minKSwaps, counter + 1);
//     }
// }

// int main()
// {
//     // Part (A)
//     string num = "";
//     int kSwaps = 0;
//     cin >> num >> kSwaps;
//     string result = num;
//     backTrack(num, result, kSwaps, 0);
//     cout << result << "\n";

//     // Part (B)
//     vector<char> nums;
//     for (int i = 0; i < num.length(); i++)
//     {
//         nums.push_back(num[i]);
//     }

//     sort(nums.begin(), nums.end());
//     reverse(nums.begin(), nums.end());

//     string maxNum = "";
//     for (int i = 0; i < nums.size(); i++)
//     {
//         maxNum += nums[i];
//     }

//     int minKSwaps = INT_MAX;
//     result = num;
//     minSwaps(num, maxNum, 0, minKSwaps, 0);
//     cout << minKSwaps;

//     return 0;
// }
////////////////////////// WITH MEMO
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

// Memoization for Part A
unordered_map<string, string> memo;

void backTrack(string num, string &ans, int kSwaps, int counter)
{
    if (kSwaps == 0)
        return;

    if (memo.find(num) != memo.end())
    {
        if (num.compare(ans) > 0)
            ans = num;
        return;
    }

    char max = num[counter];
    for (int i = counter + 1; i < num.length(); i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
    }
    if (max != num[counter])
    {
        kSwaps--;
    }
    for (int j = num.length() - 1; j >= counter; j--)
    {
        if (num[j] == max)
        {
            swap(num[j], num[counter]);
            if (num.compare(ans) > 0)
            {
                ans = num;
            }
            backTrack(num, ans, kSwaps, counter + 1);
            swap(num[j], num[counter]);
        }
    }
    memo[num] = ans;
}

// Memoization for Part B
unordered_map<string, int> minSwapsMemo;

void minSwaps(string &num, string maxNum, int swaps, int &minKSwaps, int counter)
{
    if (counter == num.length())
    {
        if (num == maxNum)
        {
            minKSwaps = min(minKSwaps, swaps);
        }
        return;
    }

    if (swaps >= minKSwaps) // If we have already used more swaps than the current minimum, return early.
        return;

    if (num[counter] != maxNum[counter])
    {
        for (int i = counter + 1; i < num.length(); i++)
        {
            if (num[i] == maxNum[counter])
            {
                swap(num[i], num[counter]);

                if (minSwapsMemo.find(num) == minSwapsMemo.end() || minSwapsMemo[num] > swaps + 1)
                {
                    minSwaps(num, maxNum, swaps + 1, minKSwaps, counter + 1);
                    minSwapsMemo[num] = swaps + 1;
                }

                swap(num[i], num[counter]); // Backtrack
            }
        }
    }
    else
    {
        minSwaps(num, maxNum, swaps, minKSwaps, counter + 1);
    }
}

int main()
{
    // Part (A)
    string num = "";
    int kSwaps = 0;
    cin >> num >> kSwaps;
    string result = num;
    backTrack(num, result, kSwaps, 0);
    cout << result << "\n";

    // Part (B)
    vector<char> nums;
    for (int i = 0; i < num.length(); i++)
    {
        nums.push_back(num[i]);
    }

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    string maxNum = "";
    for (int i = 0; i < nums.size(); i++)
    {
        maxNum += nums[i];
    }

    int minKSwaps = INT_MAX;
    result = num;
    minSwaps(num, maxNum, 0, minKSwaps, 0);
    cout << minKSwaps;

    return 0;
}
