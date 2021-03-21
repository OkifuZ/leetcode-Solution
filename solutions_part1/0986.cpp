#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int left = 0;
        int right = 0;
        int i = 0;
        int j = 0;
        vector<vector<int>> res;
        while (i < firstList.size() && j < secondList.size()) {
            int a1 = firstList[i][0];
            int a2 = firstList[i][1];
            int b1 = secondList[j][0];
            int b2 = secondList[j][1];
            if (b1 <= a2 && b2 >= a1) {
                int l = max(a1, b1);
                int r = min(a2, b2);
                res.push_back({l+1, r+1});
            }
            if (b2 > a2) i++;
            else j++;
        }
        return res;
    }
};