/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int getDepthOfPath(TreeNode* node){
        if (!node){
            return 0;
        }
        if (!node->left && !node->right){
            return 1;
        }
        return 1 + max(getDepthOfPath(node->left), getDepthOfPath(node->right));
    }
    int maxDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        if (!root->left && !root->right){
            return 1;
        }
        return 1 + max(getDepthOfPath(root->left), getDepthOfPath(root->right));
    }
};
