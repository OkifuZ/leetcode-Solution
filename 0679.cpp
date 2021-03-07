#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> ops{"plus", "minus", "multi", "div"};
    bool dfs(vector<double>& list) {
        if (list.size() == 0) {
            return false;
        }
        if (list.size() == 1) {
            return abs(list[0] - 24) < 1e-6;
        }
        for (int i = 0; i < list.size(); i++) {
            for (int j = 0; j < list.size(); j++) {
                if (i != j) {
                    vector<double> new_list;
                    for (int k = 0; k < list.size(); k++) {
                        if (k != i && k != j) {
                            new_list.push_back(list[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++) {
                        if (i > j && (ops[k] == "plus" || ops[k] == "multi")) continue;
                        double res = ops[k] == "plus" ? list[i] + list[j] :
                                ops[k] == "minus" ? list[i] - list[j] :
                                ops[k] == "multi" ? list[i] * list[j] :
                                ops[k] == "div" ? (abs(list[j]) < 1e-6 ? -1 : list[i] / list[j]) : 0;
                                if (ops[k] == "div" && abs(list[j]) < 1e-6) continue;
                        new_list.push_back(res);
                        if (dfs(new_list)) return true;
                        new_list.pop_back();
                    }
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& nums) {
        vector<double> list_;
        for (int i = 0; i < nums.size(); i++) {
            list_.push_back(static_cast<double>(nums[i]));
        }
        return dfs(list_);
    }
};