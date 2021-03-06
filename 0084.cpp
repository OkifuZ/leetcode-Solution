#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> monotonic_stack;
        heights.push_back(0);
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (monotonic_stack.empty() || heights[i] > heights[monotonic_stack.back()]) {
                monotonic_stack.push_back(i);
            }
            else if (heights[i] <= heights[monotonic_stack.back()]) {
                int cur_val = heights[i];
                while (!monotonic_stack.empty() && heights[monotonic_stack.back()] >= cur_val) {
                    int poped_height = heights[monotonic_stack.back()];
                    monotonic_stack.pop_back();
                    int poped_extent = monotonic_stack.empty() ? i : i - monotonic_stack.back() - 1;
                    max_area = max(max_area, poped_extent * poped_height);
                }
                monotonic_stack.push_back(i);
            }
        }
        return max_area;
    }
};