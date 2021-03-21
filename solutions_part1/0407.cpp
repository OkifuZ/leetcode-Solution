#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;




class Solution {
public:
struct node {
    int x_coord;
    int y_coord;
    int height;
    node(int x_coord_, int y_coord_, int height_) : 
        x_coord(x_coord_), y_coord(y_coord_), height(height_) {}
};

struct my_cmp {
    bool operator() (const node &a, const node &b) {
        return a.height > b.height;
    }
};
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<node, vector<node>, my_cmp> min_heap;
        int row_num = heightMap.size();
        int col_num = heightMap[0].size();
        vector<vector<bool>> visited(row_num, vector<bool>(col_num, false));
        for (int i = 0; i < row_num; i++) {
            visited[i][0] = visited[i][col_num-1] = true;
            min_heap.push(node(i, 0, heightMap[i][0]));
            min_heap.push(node(i, col_num-1, heightMap[i][col_num-1]));
        }
        for (int i = 1; i < col_num-1; i++) {
            visited[0][i] = visited[row_num - 1][i] = true;
            min_heap.push(node(0, i, heightMap[0][i]));
            min_heap.push(node(row_num-1, i, heightMap[row_num-1][i]));
        }
        vector<int> dir{1,0,-1,0,1};
        int res = 0;
        while (!min_heap.empty()) {
            node cur_node = min_heap.top();
            min_heap.pop();
            visited[cur_node.x_coord][cur_node.y_coord] = true;
            for (int i = 0; i < 4; i++) {
                int next_x = cur_node.x_coord + dir[i];
                int next_y = cur_node.y_coord + dir[i+1];
                if (next_x >= 0 && next_x < row_num && next_y >= 0 && next_y < col_num 
                    && !visited[next_x][next_y]) {
                    if (cur_node.height > heightMap[next_x][next_y]) {
                        res += cur_node.height - heightMap[next_x][next_y];
                    }
                    min_heap.push(node(next_x, next_y, max(cur_node.height, heightMap[next_x][next_y])));
                    visited[next_x][next_y] = true;
                }
            }
        }
        return res;
        
    }
};

int main() {

}