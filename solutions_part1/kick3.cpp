#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

long long res = 0;
int r, c;

struct node {
    int height = 0;
    int x;
    int y;
    node (int x_, int y_, int h) : x(x_), y(y_), height(h) {}
};

struct cmp {
    bool operator() (const node& a, const node& b) {
        return a.height < b.height;
    }
};

vector<int> dir{1, 0, -1, 0, 1};

void spread(vector<vector<int>> &grids, int x, int y) {
    list<pair<int, int>> que;
    que.push_back(make_pair(x, y));
    int cur_x;
    int cur_y;
    int height;
    int tem_hei;
    while (que.size()) {
        cur_x = que.front().first;
        cur_y = que.front().second;
        que.pop_front();
        height = grids[cur_x][cur_y];
        for (int i = 0; i < 4; i++) {
            int nx = cur_x + dir[i];
            int ny = cur_y + dir[i+1];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            tem_hei = grids[nx][ny];
            if (height - tem_hei > 1) {
                res += height - tem_hei - 1;
                grids[nx][ny] = height - 1;
                que.push_back(make_pair(nx, ny));
            }
        }
    }
}
int main() {
    int t;
    cin >> t;
    vector<long long> ans;
    while (t--) {
        cin >> r >> c;
        vector<vector<int>> grids(r, vector<int>(c, 0));
        priority_queue<node, vector<node>, cmp> h_que; 
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> grids[i][j];
                h_que.push(node(i, j, grids[i][j]));
            }
        }
        while (h_que.size()) {
            node cur = h_que.top();
            h_que.pop();
            spread(grids, cur.x, cur.y);
        }
        ans.push_back(res);
        res = 0;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << "Case #" << i+1 << ": " << ans[i] << endl;
    }
    return 0;
}