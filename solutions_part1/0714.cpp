#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int max_profit = 0;
        int buy_price = prices[0] + fee; // at the beginning, buy price initialized
        for (int i = 1; i < prices.size(); i++) {
            if (buy_price > prices[i]+fee) { // a lower hold price, make buy_price lower
                buy_price = prices[i] + fee;
            }
            else if (prices[i] > buy_price) { // a high price, have profit, sold it
                max_profit += prices[i] - buy_price;
                buy_price = prices[i]; // if the price increased next day, we buy it freely today
            }
        }
        return max_profit;
    }
};