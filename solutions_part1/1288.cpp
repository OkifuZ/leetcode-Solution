#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) {
                return b[1] < a[1];
            }
            return a[0] < b[0];
        });
        int left = intervals[0][0];
        int right = intervals[0][1];
        int ans = 0;
        for (auto intv = intervals.begin()+1; intv != intervals.end(); intv++) {
            if (right >= (*intv)[1]) {
                ans++;
            }
            else if (right >= (*intv)[0] && right < (*intv)[1]) {
                right = (*intv)[1];
            }
            else if (right < (*intv)[0]) {
                left = (*intv)[0];
                right = (*intv)[1];
            }
        }
        return intervals.size() - ans;
    }
};