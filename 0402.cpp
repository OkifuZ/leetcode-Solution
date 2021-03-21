#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <list>

using namespace std;



class Solution {
public:
    string removeKdigits(string num, int k) {
        list<char> mono_stack;
        for (int i = 0; i < num.size(); i++) {
            if (mono_stack.empty() || num[i] > mono_stack.back()) {
                mono_stack.push_back(num[i]);
            }
            else {
                while (k != 0 && mono_stack.back() > num[i]) {
                    k--;
                    mono_stack.pop_back();
                }   
                mono_stack.push_back(num[i]);
            }
        }
        while (k--) {
            mono_stack.pop_back();
        }
        auto it = mono_stack.begin();
        for (; it != mono_stack.end(); it++) {
            if (*it != '0') break;
        }
        string s;
        for (; it != mono_stack.end(); it++) {
            s += *it;
        }
        return s;
    }
};