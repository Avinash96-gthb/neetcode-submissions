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
    int maximumSum = INT_MIN;
    int dfs(TreeNode* node){
        if (!node){
            return 0;
        }
        int currentVal = node->val;
        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);
        maximumSum = max(maximumSum, leftSum + rightSum + currentVal);
        int localMax = max(leftSum, rightSum);
        localMax = max(localMax + currentVal, currentVal);
        maximumSum = max(maximumSum, localMax);
        return localMax;
    }
    int maxPathSum(TreeNode* root) {
        if (!root){
            return 0;
        }
        int val = dfs(root);
        return maximumSum;
    }
};
