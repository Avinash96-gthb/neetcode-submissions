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
    int kthSmallest(TreeNode* root, int k) {
        int currentVal;
        int currentGreatest = k;
        TreeNode* current = root;
        stack<TreeNode*> dfs;
        while (current || !dfs.empty()){
            while (current){
                dfs.push(current);
                current = current->left;
            }
            current = dfs.top();
            dfs.pop();
            currentGreatest--;
            cout << "is this reached" << currentGreatest;
            if (currentGreatest == 0){
                return current->val;
            }
            current = current->right;
        }
        return -1;
    }
};
