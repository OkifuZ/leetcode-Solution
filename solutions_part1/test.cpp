#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

struct node {
    int x = 0;
    int y =  0;
    node(int x_, int y_) : x(x_), y(y_) {}
};

struct comp {
    bool operator() (const node& n1, const node& n2) {
        return n1.x == n2.x ? n1.y > n2.y : n1.x < n2.x;
    }
};

int main() {
    vector<node> vec{node(1,2), node(3,4), node(9,1), node(3,8)};
    priority_queue<node, vector<node>, comp> que;
    que.push(node(3,4));
    que.push(node(2,5));
    que.push(node(1,9));
    que.push(node(9,2));
    que.push(node(3,6));
    que.push(node(3,7));
    que.push(node(8,4));
    while (que.size()) {
        cout << que.top().x << ' ' << que.top().y << endl;
        que.pop();
    }

}
