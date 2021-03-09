#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Trie {

private:
    Trie* children[26]{nullptr};
    bool end_word = false;

public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.empty()) return;
        Trie* node = this;
        for (auto &c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new Trie();
            }
            node = node->children[c - 'a'];
        }
        node->end_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (auto &c : word) {
            if (node->children[c - 'a'] == nullptr) return false;
            node = node->children[c - 'a'];
        }
        return node->end_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (auto &c : prefix) {
            if (node->children[c - 'a'] == nullptr) return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie* obj = new Trie();
    obj->insert("apple7");
    obj->insert("app");
    cout << obj->search("app");
}