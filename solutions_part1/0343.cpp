#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(60, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j*(i-j), i*dp[i-j]));
            }
        }
        return dp[n];
    }
};