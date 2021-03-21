#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), INT32_MAX));
        for (int i = 0; i < arr.size() - 1; i++) {
            dp[i][i] = 1;
            dp[i][i+1] = arr[i] == arr[i+1] ? 1 : 2;
        }
        dp[arr.size() - 1][arr.size() - 1] = 1;
        for (int length = 2; length < arr.size(); length++) {
            for (int i = 0; i + length < arr.size(); i++) {
                for (int j = i; j < i + length; j++) {
                    dp[i][i+length] = min(dp[i][i+length], dp[i][j]+dp[j+1][i+length]);
                }
                if (arr[i] == arr[i+length]) {
                    dp[i][i+length] = min(dp[i+1][i+length-1], dp[i][i+length]);
                }
                
                
                
            }
        }
        return dp[0][arr.size()-1];
    }
};