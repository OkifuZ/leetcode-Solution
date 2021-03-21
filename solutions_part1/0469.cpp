#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> index;
        stack<int> monStack;
        for (int i = nums2.size()-1; i >= 0; i--) {
            while (!monStack.empty() && nums2[monStack.top()] < nums2[i]) {
                monStack.pop();
            }
            if (monStack.empty()) {
                index[nums2[i]] = -1;
            }
            else {
                index[nums2[i]] = nums2[monStack.top()];
            }
            monStack.push(i);
        }
        vector<int> res;
        for (auto item : nums1) {
            res.push_back(index[item]);
        }
        return res;
    }
};

int main(){}