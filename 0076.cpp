#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cstdint>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;
        int valid = 0;
        int start = 0;
        int len = INT32_MAX;
        int right = 0;
        int left = 0;
        for (auto &c : t) {
            need[c]++;
        }
        while (right < s.size()) {
            char c = s[right];
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            right++;
            while (valid == need.size()) {
                if (len > right - left + 1) {
                    len = right - left + 1;
                    start = left;
                }
                c = s[left];
                left++;
                if (need.count(c)) window[c]--;
                if (need[c] > window[c]) valid--;
            }
        }
        return s.substr(start, len);
    }
};