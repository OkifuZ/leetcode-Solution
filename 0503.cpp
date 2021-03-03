#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        stack<int> monStack;
        for (int i = nums.size()*2-1; i >= 0; i--) {
            while (!monStack.empty() && monStack.top() <= nums[i%nums.size()]) {
                monStack.pop();
            }
            if (monStack.empty()) {
                res[i%nums.size()] = -1;
            }
            else {
                res[i%nums.size()] = monStack.top();
            }
            monStack.push(nums[i%nums.size()]);
        }
        return res;
    }
};

int main(){}