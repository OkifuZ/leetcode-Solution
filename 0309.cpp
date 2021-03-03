#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

/* 
    state 0: holding
    state 1: sold today
    state 2: cooldown or short

    dp[i][k]: at the end of day i, at state k, the max profit

    dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i])
    dp[i][1] = dp[i-1][0] + prices[i]
    dp[i][2] = max(dp[i-1][1], dp[i-1][2])

    cornor case:
        - dp[0][0] = -prices[0]
        - dp[0][1] = -inf
        - dp[0][2] = 0

    answer: max(dp[last][1], dp[last][2])
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = -INT32_MIN / 2;
        dp[0][2] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0] + prices[i];
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }
        return max(dp[prices.size()-1][1], dp[prices.size()-1][2]);
    }
};