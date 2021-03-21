#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

bool is_palindrome(string::iterator begin, string::iterator end) {
    end--;
    while (begin < end) {
        if (*begin != *end) return false;
        begin++;
        end--;
    }
    return true;
}

class Trie {
private:
    Trie* children[26]{nullptr};
    int index = -1;

public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word, int index) {
        if (word.empty()) { this->index = index; return; }
        Trie* node = this;
        for (auto &c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->index = index;
    }
    
    /** Returns if the word is in the trie. */
    int search(string::iterator l, string::iterator r) {
        Trie* node = this;
        r--;
        while (l <= r) {
            if (node->children[*r - 'a'] == nullptr) {
                return -1;
            }
            node = node->children[*r - 'a'];
            r--;
        }
        return node->index;
    }
};

class Solution {
public:

    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie t;
        set<vector<int>> res;
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++) {
            t.insert(words[i], i);
        }
        for (int i = 0; i < words.size(); i++) {
            string &word = words[i];
            for (int j = 0; j <= word.size(); j++) {
                if (is_palindrome(word.begin() + j, word.end())) {
                    int index = t.search(word.begin(), word.begin() + j);
                    if (i != index && index != -1) {
                        res.insert({i, index});
                    }
                }
                if (is_palindrome(word.begin(), word.begin() + j)) {
                    int index = t.search(word.begin() + j, word.end());
                    if (i != index && index != -1) {
                        res.insert({index, i});
                    }
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

int main() {
    Solution s;
    vector<string> v{"ab","ba"};
    s.palindromePairs(v);
}