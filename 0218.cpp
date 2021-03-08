#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;


class SegmentTree {
    vector<int> segment_tree_max;
    int length;
    vector<int> lazy;

public:
    SegmentTree(int len) {
        // range within interval [1, len]
        this->segment_tree_max = vector<int>(len*4);
        this->lazy = vector<int>(len*4, 0); // zero is vital
        this->length = len;
    }

    void update(int a, int b, int value) {
        _update(a, b, 1, this->length, value, 1);
    }

    void _update(int l, int r, int a, int b, int value, int node_index) {
        // [l, r] is target interval
        // [a, b] is current interval
        if (l <= a && b <= r) {
            segment_tree_max[node_index] = value;
            lazy[node_index] = value;
            return;
        }
        int m = (a + b) / 2;
        if (lazy[node_index] != 0) {
            segment_tree_max[node_index*2] = lazy[node_index*2] = lazy[node_index];
            segment_tree_max[node_index*2+1] = lazy[node_index*2+1] = lazy[node_index];
            lazy[node_index] = 0;
        }   
        if (l <= m) _update(l, r, a, m, value, node_index*2);
        if (r > m) _update(l, r, m+1, b, value, node_index*2+1);
    }

    int getMax(int a, int b) {
        return _getMax(a, b, 1, this->length, 1);
    }

    int _getMax(int l, int r, int a, int b, int node_index) {
        if (l <= a && b <= r) return segment_tree_max[node_index];
        int m = (a + b )/2;
        if (lazy[node_index]) {
            segment_tree_max[node_index*2] = lazy[node_index*2] = lazy[node_index];
            segment_tree_max[node_index*2+1] = lazy[node_index*2+1] = lazy[node_index];
            lazy[node_index] = 0;
        }
        int max_value = 0;
        if (l <= m) max_value = max(max_value, _getMax(l, r, a, m, node_index*2));
        if (m+1 <= r) max_value = max(max_value, _getMax(l, r, m+1, b, node_index*2+1));
        return max_value;
    }
};


class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.empty()) return vector<vector<int>>();
        map<int, int> squeeze_map; // coordinates to incremental numbers
        map<int, int> strech_map; // numbers to coordinates
        set<int> coords_set; // coordinates
        sort(buildings.begin(), buildings.end(), [](vector<int> a, vector<int> b) { return a[2] < b[2]; });
        for (auto building : buildings) {
            coords_set.insert(building[0]);
            coords_set.insert(building[1]);
        }
        vector<int>coords_vec(coords_set.begin(), coords_set.end());
        sort(coords_vec.begin(), coords_vec.end());
        for (int i = 0; i < coords_vec.size(); i++) {
            squeeze_map.insert(make_pair(coords_vec[i], i+1));
            strech_map.insert(make_pair(i+1, coords_vec[i]));
        }
        int nums = strech_map.size();
        SegmentTree seg_tree(nums);
        for (auto building : buildings) {
            seg_tree.update(squeeze_map[building[0]], squeeze_map[building[1]] - 1, building[2]); // minus one is vital
        }
        vector<vector<int>> res;
        int last_height = -1, current_height = 0;
        for (int i = 1; i <= nums; i++) {
            current_height = seg_tree.getMax(i, i);
            if (current_height != last_height) {
                res.push_back({strech_map[i], current_height});
                last_height = current_height;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> t{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    Solution s;
    auto ans = s.getSkyline(t);
    for (auto p : ans) {
        cout << p[0] << ' ' << p[1] << endl;
    }
}