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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> bfs;
        if (root){
            bfs.push(root);
        }
        while(!bfs.empty()){
            vector<int> level;
            vector<TreeNode*> children;
            while (!bfs.empty()){
                level.push_back(bfs.front()->val);
                children.push_back(bfs.front());
                bfs.pop();
            }
            for (TreeNode* node: children){
                if (node->left){
                    bfs.push(node->left);
                }
                if (node->right){
                    bfs.push(node->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
