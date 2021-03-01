#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int* tree;
int epoch;
int length;
int len = 1;

int query(int a, int b, int l, int r, int k) {
    // no intersect
    if (l > r) {
        return 0;
    }
    if (a > r || b < l) { 
        return 0;
    }
    // the node was fully covered by the target interval
    if (a <= l && b >= r) {
        return tree[k];
    }
    // the node covers the target interval, but doesn't fit
    if (l < a || r > b) {
        int left = query(a, b, l, (l+r)/2, k*2);
        int right = query(a, b, (l+r)/2+1, r, k*2+1);
        return left + right;
    }
}

void add(int i, int n) {
    i = len + i;
    while (i != 0) {
        tree[i] += n;
        i /= 2;
    }
}

void sub(int i, int n) {
    i = len + i;
    while (i != 0) {
        if (tree[i] >= n)
            tree[i] -= n;
        else
            tree[i] = 0; 
        i /= 2;
    }
}

int main() {
    cin >> epoch;
    for (int k = 0; k < epoch; k++) {
        cout << "Case " << k+1 << ":\n";
        cin >> length;
        
        while (len < length) {
            len *= 2;
        }
        // build the tree
        tree = new int[len*2]();
        for (int i = 0; i < length; i++) {
            int val;
            cin >> val;
            add(i, val);
        } 
        // read options
        string opt;
        while (true) {
            cin >> opt;
            if (opt == "End") {
                break;
            }
            int x, y;
            cin >> x >> y;
            if (opt == "Query") {
                cout << query(x-1, y-1, 0, len-1, 1) << "\n";
            }
            else if (opt == "Add") {
                add(x-1, y);
            }
            else if (opt == "Sub") {
                sub(x-1, y);
            }
        }
    }
    return 0;
}