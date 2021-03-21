#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



class Solution {
public:
    bool check(int x, int y, int k) {
        return x % 10 + x / 10 % 10 + x / 100 + y % 10 + y / 10 % 10 + y / 100 <= k;
    }
    int m, n;
    int dfs(int i, int j, vector<vector<bool>>& vis, int k) {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j]) {
            return 0;
        }
        if (!check(i, j, k)) {
            return 0;
        }
        vis[i][j] = true;
        return 1 + dfs(i + 1, j, vis, k) +
             dfs(i-1, j, vis, k) +
            dfs(i, j + 1, vis, k) +
         dfs(i, j-1, vis, k);
    }

    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        this->m = m;
        this->n = n;
        return dfs(0, 0, visited, k);
    }
};

int main() {
    Solution s;
    cout << s.movingCount(14, 14, 5);
}