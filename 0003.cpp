#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        vector<int> freq(300, 0);
        while (left < s.size()) {
            if (right < s.size() && freq[s[right]] == 0) {
                freq[s[right]]++;
                right++;
            }
            else if (left < right) {
                freq[s[left]]--;
                left++;
            }
            maxLength = (maxLength > right - left) ? maxLength : right - left;
        }
        return maxLength;
    }
};

int main() {
    string s = "pwwkew";
    string ss = "";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s);
    cout << sol.lengthOfLongestSubstring(ss);
}