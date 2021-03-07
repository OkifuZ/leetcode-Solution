#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <cstdint>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int max_sum = INT32_MIN;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_path = max(0, dfs(root->left));
        int right_path = max(0, dfs(root->right));
        max_sum = max(max_sum, left_path + right_path + root->val);
        return root->val + max(left_path, right_path); 

    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_sum;
    }
};