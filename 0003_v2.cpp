#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        int left = 0, right = 0, max_len = 0;
        while (right < s.size()) {
            char c = s[right];
            while (window.count(c)) {
                char c_ = s[left];
                left++;
                if (window.count(c_)) {
                    window[c_]--;
                }
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};