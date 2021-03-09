#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Trie {

private:
    Trie* children[2]{nullptr};
    int number = -1;

public:
    /** Initialize your data structure here. */
    Trie() {}
    
    void insert(int num) {
        Trie* node = this;
        for (int i = 30; i >= 0; i--) {
            int bit = num >> i & 1;
            if (node->children[bit] == nullptr) {
                node->children[bit] = new Trie();
            }
            node = node->children[bit];
        }
        node->number = num;
    }

    int search(int num) {
        Trie* node = this;
        for (int i = 30; i >= 0; i--) {
            int bit = num >> i & 1;
            if (node->children[1 - bit]) {
                node = node->children[1 - bit];
            }
            else {
                node = node->children[bit];
            }
        }
        return node->number ^ num;
    }

};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for (auto &num: nums) {
            t.insert(num);
        }
        int max_xor = 0;
        for (auto &num: nums) {
            max_xor = max(max_xor, t.search(num));
        }
        return max_xor;
    }
};