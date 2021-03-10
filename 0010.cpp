#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:

    bool dfs(const string& s, const string& p, map<pair<string, string>, bool>& memo) {
        if (p.empty()) return s.empty();
        if (memo.find(make_pair(s, p)) != memo.end()) {
            return memo[make_pair(s, p)];
        }
        bool res = false;
        if (p.size() > 1 && p[1] == '*') {
            res |= dfs(s, p.substr(2, p.size() - 2), memo);
            if (s.size() > 0 && (p[0] == '.' || p[0] == s[0])) {
                res |= dfs(s.substr(1, s.size() - 1), p, memo);
            }
        }
        else if (s.size() > 0 && (p[0] == '.' || p[0] == s[0])) {
            res |= dfs(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1), memo);
        }
        memo[make_pair(s, p)] = res;
        return res;
    }

    bool isMatch(string s, string p) {
        map<pair<string, string>, bool> memo;
        return dfs(s, p, memo);
    }
};