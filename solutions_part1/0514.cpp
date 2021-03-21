#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cstdint>

using namespace std;

int my_min(int a, int b) {
    return a < b ? a : b;
}

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> pos_map;
        for (int i = 0; i < ring.size(); i++) {
            pos_map[ring[i]].push_back(i);
        }
        vector<vector<int>> dp(ring.size(), vector<int>(key.size(), 0x3f3f3f3f));
        // dp[i][j] means that current pointer points to ring[i] and key[1...j] has been typed
        // dp[i][j] = minimal value {dp[j-1][k] + min(abs(i - k), n - abs(i - k) + 1)} + 1 where k in pos_map[ring[j-1]]   
        for (auto &k : pos_map[key[0]]) {
            dp[k][0] = my_min(k, ring.size()-k) + 1;
        }
        for (int j = 1; j < key.size(); j++) {
            for (auto &i : pos_map[key[j]]) { // current pointer
                for (auto &k : pos_map[key[j-1]]) { // last pointer
                    dp[i][j] = my_min(dp[i][j], dp[k][j-1] + my_min(abs(i-k), ring.size() - abs(i-k)) + 1);
                } 
            }
        }
        int res = INT32_MAX;
        for (int i = 0; i < ring.size(); i++) {
            res = min(res, dp[i][key.size()-1]);
        }
        return res;
    }
};

int main() {

}