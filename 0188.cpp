#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;

        vector<vector<int>> dp(prices.size(), vector<int>(k*2, 0));
        for (int i = 0; i < k; i++) {
            dp[0][i*2] = -prices[0];
        }      
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            for (int j = 1; j < k; j++) {
                dp[i][j*2-1] = max(dp[i-1][j*2-1], dp[i-1][j*2-2] + prices[i]);
                dp[i][j*2] = max(dp[i-1][j*2], dp[i-1][j*2-1] - prices[i]);
            }
            dp[i][2*k-1] = max(dp[i-1][2*k-1], dp[i-1][2*k-2] + prices[i]);
        }

        return dp[prices.size()-1][2*k-1];
    }

};

int main() {
    Solution s;
    auto myvec = vector<int>{2,4,1};
    s.maxProfit(2, myvec);
}