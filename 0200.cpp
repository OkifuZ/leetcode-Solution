#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> dir_next{1, 0, -1, 0, 1};
    void dfs(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
        visited[x][y] = true;
        int next_x, next_y;
        for (int i = 0; i < 4; i++) {
            next_x = x + dir_next[i];
            next_y = y + dir_next[i + 1];
            if (next_x >= 0 && next_x < grid.size() && next_y >= 0 && next_y < grid[0].size()) {
                if (!visited[next_x][next_y]) {
                    if (grid[next_x][next_y] == '1') {
                        dfs(grid, next_x, next_y, visited);
                    }        
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    ans++;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return ans;
    }
};