#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdint>

using namespace std;


int *tree;
int len = 1;

void update(int i, int n) {
    i = len + i;
    tree[i] = n;
    i /= 2;
    while (i != 0) {
        tree[i] = max(tree[i*2], tree[i*2+1]);
        i /= 2;
    }
}

int query(int a, int b, int l, int r, int k) {
    if (l > r) {
        return INT32_MIN;
    }
    if (a > r || b < l) {
        return INT32_MIN;
    }
    if (a <= l && b >= r) {
        return tree[k];
    }
    int left_max = query(a, b, l, (l+r)/2, k*2);
    int right_max = query(a, b, (l+r)/2+1, r, k*2+1);
    return left_max > right_max ? left_max : right_max;
}

int main() {
    int n, t;
    while (scanf("%d %d", &n, &t) != EOF) {
        while (len < n) {
            len *= 2;
        }
        tree = new int[len*2]();
        int score;
        for (int i = 0; i < n; i++) {
            scanf("%d", &score);
            update(i, score);
        }
        int x, y;
        char s[1];  
        for (int i = 0; i < t; i++) {
            // getchar();
            scanf("%s%d%d", s, &x, &y);
            if (s[0] == 'U') {
                update(x-1, y);
            }
            else if (s[0] == 'Q') {
                printf("%d\n", query(x-1, y-1, 0, len-1, 1));
            }
        }
    }
    return 0;
}