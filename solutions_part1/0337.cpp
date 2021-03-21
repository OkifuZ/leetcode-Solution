#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    struct DpNode {
        int val_t;
        int val_nt;
        DpNode *left;
        DpNode *right;
        DpNode(int t, int nt, DpNode* lc, DpNode* rc) : val_t(t), val_nt(nt), left(lc), right(rc) {}
    };
    DpNode* constructDpTree (TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
           return new DpNode(root->val, 0, nullptr, nullptr); 
        }
        DpNode *left_dp = nullptr, *right_dp = nullptr;
        if (root->left != nullptr) {
            left_dp = constructDpTree(root->left);
        }
        if (root->right != nullptr) {
            right_dp = constructDpTree(root->right);
        }
        if (left_dp != nullptr && right_dp != nullptr) {
            int t = root->val + left_dp->val_nt + right_dp->val_nt;
            int nt = max(max(left_dp->val_t+right_dp->val_t, left_dp->val_nt+right_dp->val_nt), 
                         max(left_dp->val_t+right_dp->val_nt, left_dp->val_nt+right_dp->val_t));
            return new DpNode(t, nt, left_dp, right_dp);
        }
        if (left_dp != nullptr && right_dp == nullptr) {
            int t = root->val + left_dp->val_nt;
            int nt = max(left_dp->val_nt, left_dp->val_t);
            return new DpNode(t, nt, left_dp, nullptr);
        }
        if (left_dp == nullptr && right_dp != nullptr) {
            int t = root->val + right_dp->val_nt;
            int nt = max(right_dp->val_nt, right_dp->val_t);
            return new DpNode(t, nt, nullptr, right_dp);
        }
        // won't reach
        return nullptr;
    }

    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        DpNode* ans = constructDpTree(root);
        return max(ans->val_nt, ans->val_t);
    }

    

};

// bfs, wrong in some test case!
// class Solution {
// public:
//     int rob(TreeNode* root) {
//         vector<TreeNode*> que, new_que;
//         if (root == nullptr) return 0;
//         que.push_back(root);
//         int level = 0;
//         int odd = 0, even = 0;
//         while (que.size()) {
//             level++;
//             for (int i = 0; i < que.size(); i++) {
//                 TreeNode* t = que[i];
//                 if (level % 2 == 0) {
//                     even += t->val;
//                 }
//                 else {
//                     odd += t->val;
//                 }
//                 if (t->left != nullptr) new_que.push_back(t->left);
//                 if (t->right != nullptr) new_que.push_back(t->right);
//             }
//             swap(que, new_que);
//             new_que.clear();
//         }
//         return max(odd, even);
//     }
// };