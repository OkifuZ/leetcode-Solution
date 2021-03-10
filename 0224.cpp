#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <sstream>
using namespace std;



class Solution {
public:

    bool get_next_char(char& c, istream& in) {
        while (true) {
            c = in.get();
            if (c == -1) return false;
            if (c != ' ') return true;
        }
    }

    int calculate(string s) {
        stack<int> num_stack;
        stack<char> ops_stack;
        char c;
        int num;
        num_stack.push(0);
        const string& ss = s;
        istringstream in(ss);
        while (get_next_char(c, in)) {
            if (c == '(') ops_stack.push(c);
            else if (c == '+' || c == '-') {
                while (!ops_stack.empty() && ops_stack.top() != '(') {
                    int a, b, o;
                    o = ops_stack.top();
                    ops_stack.pop();
                    b = num_stack.top();
                    num_stack.pop();
                    a = num_stack.top();
                    num_stack.pop();
                    if (o == '+')
                        num_stack.push(a + b);
                    else if (o == '-')
                        num_stack.push(a - b);
                }
                ops_stack.push(c);
            }
            else if (c == ')') {
                int a, b, o;
                while (ops_stack.top() != '(') {
                    b = num_stack.top();
                    num_stack.pop();
                    a = num_stack.top();
                    num_stack.pop();
                    if (ops_stack.top() == '+') {
                        num_stack.push(a + b);
                    }
                    else {
                        num_stack.push(a - b);
                    }
                    ops_stack.pop();
                }
                ops_stack.pop();
            }
            else {
                num = 0;
                while (c <= '9' && c >= '0') {
                    num *= 10;
                    num += c - '0';
                    get_next_char(c, in);
                }
                if (c != EOF) in.putback(c);
                num_stack.push(num);
            }
        }
        while (ops_stack.size()) {
            int a, b, o;
            o = ops_stack.top();
            ops_stack.pop();
            b = num_stack.top();
            num_stack.pop();
            a = num_stack.top();
            num_stack.pop();
            if (o == '+')
                num_stack.push(a + b);
            else if (o == '-')
                num_stack.push(a - b);
        }
        return num_stack.top();
    }
};
