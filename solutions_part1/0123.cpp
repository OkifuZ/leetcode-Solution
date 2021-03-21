#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <stack>

using namespace std;

class Solution {
public:
    /* method 1: dp, 4 states */
    /* int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][1] = -prices[0];
        dp[0][2] = dp[0][3] = INT32_MIN;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i]);
        }
        return max(dp[prices.size()-1][1], dp[prices.size()-1][3]);
    } */

    /* method 2: greedy(monotonic stack) */
    int maxProfit(vector<int>& prices) {
        vector<int> decreasing_stack;
        vector<int> second_trade_profitMax(prices.size());
        int max_profit = INT32_MIN;
        for (int i = prices.size() - 1; i >= 0; i--) {
            while (!decreasing_stack.empty() && prices[i] >= decreasing_stack.back()) {
                decreasing_stack.pop_back();
            }
            decreasing_stack.push_back(prices[i]);
            max_profit = max(decreasing_stack[0] - prices[i], max_profit);
            second_trade_profitMax[i] = max_profit;
        }
        vector<int> increasing_stack;
        int ans = INT32_MIN;
        max_profit = INT32_MIN;
        for (int i = 0; i < prices.size(); i++) {
            while (!increasing_stack.empty() && prices[i] <= increasing_stack.back()) {
                increasing_stack.pop_back();
            }
            increasing_stack.push_back(prices[i]);
            max_profit = max(prices[i] - increasing_stack[0], max_profit);
            ans = max(max_profit + second_trade_profitMax[i], ans);
        }
        return ans;
    }
    
};

int main() {
    Solution s;
    auto myvec = vector<int>{1,2,3,4,5};
    cout << s.maxProfit(myvec);
}