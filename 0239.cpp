#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <deque>

using namespace std;

class Solution {
public:
    struct MonotomicQueue {
        deque<int> que;
        void push(int n) {
            while (!que.empty() && que.back() < n) { // here it must be que.back() < n, or it would cause error
                que.pop_back();
            }
            que.push_back(n);
        }

        int max() {
            return que.empty() ? INT32_MIN : que.front();
        }

        void pop(int n) {
            if (!que.empty() && que.front() == n) {
                que.pop_front();
            }
        }
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MonotomicQueue monoQue;
        for (int i = 0; i < nums.size(); i++) {
            if (i < k - 1) {
                monoQue.push(nums[i]);
            }
            else {
                monoQue.push(nums[i]);
                res.push_back(monoQue.max());

                monoQue.pop(nums[i-k+1]);
            }
        }
        return res;

    }
};