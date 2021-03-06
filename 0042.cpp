#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        vector<int> increasing_vec;
        int pillar_volume = 0;
        for (int i = 0; i < height.size(); i++) {
            pillar_volume += height[i];
            if (increasing_vec.empty() || height[increasing_vec.back()] < height[i]) {
                increasing_vec.push_back(i);
            }
        }
        vector<int> increasing_vec_reverse;
        for (int i = height.size()-1; i >= 0; i--) {
            if (increasing_vec_reverse.empty() || height[increasing_vec_reverse.back()] < height[i]) {
                increasing_vec_reverse.push_back(i);
            }
        }
        int forward_size = 0, backward_size = 0;
        int highest_pos = 0, highest = 0;
        for (auto convex_pos : increasing_vec) {
            forward_size += (convex_pos - highest_pos) * highest;
            highest = height[convex_pos];
            highest_pos = convex_pos;
        }
        highest_pos = highest = 0;
        for (auto convex_pos : increasing_vec_reverse) {
            backward_size += (highest_pos - convex_pos) * highest;
            highest = height[convex_pos];
            highest_pos = convex_pos;
        }
        return height[increasing_vec.back()] + forward_size + backward_size - pillar_volume;
    }
};

int main() {
    Solution s;
    vector<int> ss{1,2,3};
    s.trap(ss);
}