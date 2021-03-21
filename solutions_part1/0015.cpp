#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }
        int a, b, c, sum;
        sort(nums.begin(), nums.end());
        
        for (a = 0; a < nums.size() - 2; a++) {
            if (a != 0 && nums[a] == nums[a-1]) continue;
            b = a + 1;
            c = nums.size() - 1;
            while (b < c) {
                sum = nums[a] + nums[b] + nums[c];
                int flag = -1;
                if (sum == 0) {
                    ans.push_back(vector<int>{nums[a], nums[b], nums[c]});
                } 
                flag = sum == 0 ? 0 : sum > 0 ? 1 : 2;
                if (flag == 0 || flag == 1) {
                    do {
                        c--;
                    } while (nums[c+1] == nums[c] && c > b);
                }
                if (flag == 0 || flag == 2) {
                    do {
                        b++;
                    } while (nums[b-1] == nums[b] && b < c);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v{0,0,0,0};
    auto ans = s.threeSum(v);
    for (auto i : ans) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}