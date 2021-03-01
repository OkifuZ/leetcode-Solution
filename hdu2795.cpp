#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// something wrong, always WA

int* tree;
int len = 1;
int h, w, t;

void update(int i, int n) {
    i = len + i;
    tree[i] = n;
    i /= 2;
    while (i != 0) {
        tree[i] = max(tree[i*2], tree[i*2+1]);
        i /= 2;
    }
}

int query(int length, int l, int r, int k) {
    if (length > tree[k] || l > r) return -1;
    // leaf node
    if (l == r) {
        update(l, tree[k] - length);
        return l;
    }
    int left = query(length, l, (l+r)/2, k*2);
    if (left != -1) {
        return left;
    }
    int right = query(length, (l+r)/2 +1, r, k*2+1);
    return right;

}

int main() {
    while (scanf("%d%d%d", &h, &w, &t) != EOF) {
        h = min(h, t+1);
        while (len < h) {
            len*= 2;
        }
        tree = new int[len*2]();
        for (int i = 0; i < h; i++) {
            update(i, w);
        }
        int length;
        for (int i = 0; i < t; i++) {
            scanf("%d", &length);
            int res = query(length, 0, len-1, 1);
            res = res == -1 ? res : res + 1;
            printf("@%d\n", res);
        }
        delete [] tree;
    }
}