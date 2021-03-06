#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:

    TreeNode* ans = nullptr;

    bool find_anc(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool self_get = false;
        if (root == nullptr) {
            return 0;
        }    
        if (root->val == p->val) {
            self_get = true;
        }
        if (root->val == q->val) {
            self_get = true;
        }
        bool res_left = find_anc(root->left, p, q);
        bool res_right = find_anc(root->right, p, q);
        if (res_left && res_right) {
            ans = ans == nullptr ? root : ans;
            return true;
        }
        else if (res_left || res_right) {
            if (self_get) {
                ans = ans == nullptr ? root : ans;
            }
            return true;
        }
        else {
            return self_get;
        }

    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find_anc(root, p, q);
        return ans;
    }
};