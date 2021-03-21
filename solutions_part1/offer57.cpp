#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int i, j;
        int sum = 3;
        vector<vector<int>> res;
        for (i = 1, j = 2; i != j; ) {
            if (sum == target) {
                vector<int> tem;
                for (int k = i; k <= j; k++) {
                    tem.push_back(k);
                }
                res.push_back(tem);
                sum -= i;
                i++;
            }
            else if (sum < target) {
                j++;
                sum += j;
            }
            else if (sum > target) {
                sum -= i;
                i++;
            }
        }
        return res;
    }
};