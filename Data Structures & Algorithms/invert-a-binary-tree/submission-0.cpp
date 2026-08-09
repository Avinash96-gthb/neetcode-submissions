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
    void invertSubtree(TreeNode* node){
        if (!node){
            return;
        } 
        if (!node->left && !node->right){
            return;
        }
        TreeNode* tempLeft = node->left;
        TreeNode* tempRight = node->right;
        node->left = tempRight;
        node->right = tempLeft;
        invertSubtree(node->left);
        invertSubtree(node->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertSubtree(root);
        return root;
    }
};
