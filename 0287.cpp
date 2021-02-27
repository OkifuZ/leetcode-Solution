#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 2) {
            return 1;
        }
        int fast = 0, slow = 0;
        bool flag = false;
        while (true) {
            if (flag && fast == slow) {
                break;
            }
            flag = true;
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

int main() {
    vector<int> nums{1,1,2};
    Solution s;
    cout << s.findDuplicate(nums);
}