#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdint>
using namespace std;


class Solution {
public:
    int numSquares(int n) {
        int lens = sqrt(n);
        vector<int> squaress(lens+1, 0);
        for (int i = 1; i <= lens; i++) {
            squaress[i] = i*i;
        }
        vector<int> dp(n+1, INT32_MAX);
        dp[1] = 1;
        dp[0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= lens; j++) {
                if (squaress[j] > i) {
                    break;
                }
                dp[i] = min(dp[i], dp[i-squaress[j]]+1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    cout << s.numSquares(12);

}
