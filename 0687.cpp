#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* constructTree(vector<int> nums) {
    if (nums.empty()) return nullptr;
    TreeNode* root = new TreeNode(nums[0], nullptr, nullptr);
    queue<TreeNode*> que;
    que.push(root);
    int i = 1;
    while (!que.empty() && i < nums.size()) {
        TreeNode* cur_node = que.front();
        que.pop();
        cur_node->left = new TreeNode(nums[i], nullptr, nullptr);
        que.push(cur_node->left);
        i++;
        if (i >= nums.size()) break;
        cur_node->right = new TreeNode(nums[i], nullptr, nullptr);
        que.push(cur_node->right);
        i++;
    }
    return root;
}

class Solution {
public:
    int max_length = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left_path = dfs(root->left);
        int right_path = dfs(root->right);
        if (root->left != nullptr) {
            left_path = (root->left->val == root->val ? left_path + 1 : 0);
        }
        if (root->right != nullptr) {
            right_path = (root->right->val == root->val ? right_path + 1 : 0);
        }
        max_length = max(max_length, left_path + right_path);
        return max(left_path, right_path);
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return max_length;
    }
};

int main() {
    vector<int> nums = {1,4,5,4,4,5};
    TreeNode* root = constructTree(nums);
    Solution s;
    cout << s.longestUnivaluePath(root);
}