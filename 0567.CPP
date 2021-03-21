#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window, need;
        int left = 0, right = 0;
        int valid = 0;
        for (auto &c : s1) {
            need[c]++;
        }
        while (right < s2.size()) {
            char c = s2[right];
            if (need.count(c)) {
                window[c]++;
                if (need[c] == window[c]) valid++;
            }
            right++;
            if (right - left >= s1.size()) {
                if (valid == need.size()) return true;
                c = s2[left];
                if (need.count(c)) {
                    if (window[c] == need[c]) valid--; 
                    window[c]--;
                }
                left++;
            }
        }
        return false;
    }
};