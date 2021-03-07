#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<int> dir{1, 0, -1, 0, 1};
    int row, col;
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& length, vector<vector<bool>>& visited, int x, int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dir[i];
            int ny = y + dir[i+1];
            if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
                if (matrix[nx][ny] > matrix[x][y]) {
                    length[x][y] = max(length[nx][ny] + 1, length[x][y]);
                    if (!visited[nx][ny])
                        dfs(matrix, length, visited, nx, ny);
                }
            }
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();
        vector<vector<int>> length(row, vector<int>(col, 1));
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j]) {
                    dfs(matrix, length, visited, i, j);
                }
            }
        }
        int max_len = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                max_len = max(length[i][j], max_len);
            }
        }
        return max_len;
    }
};