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
 //         3
 //.     1.    4 
 //.   3.  n. 1.  5

class Solution {
public:
    int totalGoodNodes = 0;
    void dfs (TreeNode* node, int maxValue){
        if (!node){
            return;
        }
        if (node->val >= maxValue){
            cout << "the good node value is" << node->val;
            totalGoodNodes++;
        }
        dfs(node->left, max(maxValue, node->val));
        dfs(node->right, max(maxValue, node->val));
    }
    int goodNodes(TreeNode* root) {
        if (!root){
            return 0;
        }
        totalGoodNodes++;
        dfs(root->left, root->val);
        dfs(root->right, root->val);
        return totalGoodNodes;
    }
};
