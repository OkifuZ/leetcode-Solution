#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     vector<int> dp(nums.size(), 1);
    //     for (int i = 1; i < nums.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (nums[j] > nums[i]) {
    //                 dp[i] = max(dp[j]+1, dp[i]);
    //             }
    //         }
    //     }
    //     int max_length = 0;
    //     for (int i = 0; i < nums.size(); i++) {
    //         max_length = max(max_length, dp[i]);
    //     }
    //     return max_length;
    // }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail(nums.size(), INT32_MIN);
        int len = 0;
        vector<int> dp(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            // int j;
            // j is the index that tail[j] is the first number *bigger than or equal to* nums[i]
            // or tail[j] is INT_MIN, i.e. no element in tail is bigger than nums[i]
            
            /* method 1: brute force
            int j;
            for (j = 0; j < len; j++) {
                if (nums[i] <= tail[j]) {
                    tail[j] = nums[i];
                    break;
                }
            }
            if (j == len) {
                tail[len++] = nums[i];
            }
            tail[j] = nums[i]; */
            
            // method 2: binaray search
            int l = 0, r = len-1, mid;
            while (l < r) {
                mid = (l + r) >> 1;
                if (tail[mid] >= nums[i]) {
                    r = mid;
                }
                else {
                    l = mid+1;
                }
            }
            if (tail[l] < nums[i]) {
                tail[len++] = nums[i];
            }
            else {
                tail[l] = nums[i];
            }

        }
        return len;
    }
};