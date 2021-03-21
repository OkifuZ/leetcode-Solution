#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

    class Solution {
    public:
        string upside(string s, int i) {
            if (s[i] == 9) {
                s[i] = '0';
            }
            else {
                s[i] += 1;
            }
            return s;
        }

        string downside(string s, int i) {
            if (s[i] == 0) {
                s[i] = '9';
            }
            else {
                s[i] -= 1;
            }
            return s;
        }

        int openLock(vector<string>& deadends, string target) {
            if (target == "0000") return 0;
            int ans = 0;
            set<string> dead(deadends.begin(), deadends.end());
            list<string> que;
            que.push_back("0000");
            dead.insert("0000");
            while (que.size()) {
                ans++;
                for (int k = 0; k < que.size(); k++) {
                    string s = que.back();
                    que.pop_back();
                    for (int i = 0; i < 4; i++) {
                        string up = upside(s, i);
                        string down = downside(s, i);
                        if (!dead.count(up)) {
                            if (up == target) return ans;
                            dead.insert(up);
                            que.push_back(up);
                        }
                        if (!dead.count(down)) {
                            if (down == target) return ans;
                            dead.insert(down);
                            que.push_back(down);
                        }
                    }
                }
                return -1;
            }
        }
    };