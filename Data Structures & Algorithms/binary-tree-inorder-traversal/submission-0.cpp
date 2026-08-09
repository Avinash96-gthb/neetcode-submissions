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
    vector<int> returnInOrderTraversedSubTree(TreeNode* node){
        vector<int> result;
        if (!node->left && !node->right){
            result.push_back(node->val);
            return result;
        }
        if (node->left){
            vector<int> leftVector = returnInOrderTraversedSubTree(node->left);
            result.insert(result.end(), leftVector.begin(), leftVector.end());
        }
        result.push_back(node->val);
        if (node->right){
            vector<int> rightVector = returnInOrderTraversedSubTree(node->right);
            result.insert(result.end(), rightVector.begin(), rightVector.end());
        }
        return result;

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root){
            return result;
        }
        if (root->left){
            vector<int> leftVector = returnInOrderTraversedSubTree(root->left);
            result.insert(result.end(), leftVector.begin(), leftVector.end());
        }
        result.push_back(root->val);
        if (root->right){
            vector<int> rightVector = returnInOrderTraversedSubTree(root->right);
            result.insert(result.end(), rightVector.begin(), rightVector.end());
        }
        return result;
    }
};