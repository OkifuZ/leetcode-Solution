#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int res = 0;

int r, c;

// 0: right 1: down 2: left 3: up

void calc(vector<vector<int>> &grids, int x, int y, int dx, int dy) {
    int num_x = 1;
    int num_y = 1;
    while (true) {
        int ny = y+dy*num_y;
        if (ny < 0 || ny >= c) break;
        if (grids[x][ny] == 0) break;
        num_y++;
    }
    while (true) {
        int nx = x+dx*num_x;
        if (nx < 0 || nx >= r) break;
        if (grids[nx][y] == 0) break;
        num_x++;
    }
    if (num_x == 1 || num_y == 1) return;
    if (num_x * 2 <= num_y) res += num_x - 1;
    else res += num_y / 2 - 1;
    if (num_y * 2 <= num_x) res += num_y - 1;
    else res += num_x / 2 - 1;
}

int main() {
    int t;
    cin >> t;
    vector<int> ans;
    while (t--) {
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    calc(grid, i, j, 1, 1);
                    calc(grid, i, j, -1, 1);
                    calc(grid, i, j, 1, -1);
                    calc(grid, i, j, -1, -1);
                }
            }
        }
        ans.push_back(res);
        res = 0;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << "Case #" << i+1 << ": " << ans[i] << endl;
    }
}