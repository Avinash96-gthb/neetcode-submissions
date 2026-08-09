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
    stack<TreeNode*> smallestStack;
    void putSmallestNodesInStack(TreeNode* node){
        if (!node){
            return;
        }
        putSmallestNodesInStack(node->right);
        smallestStack.push(node);
        putSmallestNodesInStack(node->left);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        if (!root){
            return 0;
        }
        putSmallestNodesInStack(root);
        while (!smallestStack.empty()){
            TreeNode* node = smallestStack.top();
            smallestStack.pop();
            k--;
            if (k==0){
                return node->val;
            }
        }
        return -1;
    }
};
