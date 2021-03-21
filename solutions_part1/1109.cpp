#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> res(n, 0);
        for (auto &booking : bookings) {
            int l = booking[0];
            int r = booking[1];
            int v = booking[2];
            res[l] += v;
            res[r] -= v;
        }
        for (int i = 1; i < res.size(); i++) {
            res[i] += res[i-1];
        }
        return res;
    }
};