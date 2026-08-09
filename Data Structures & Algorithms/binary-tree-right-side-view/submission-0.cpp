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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root){
            return ans;
        }
        queue<TreeNode*> bfs;
        bfs.push(root);
        int queueCount = 1;
        while (!bfs.empty()){
            bool isAddedList = false;
            int localCount = 0;
            for (int i = 0; i < queueCount; i++){
                TreeNode* node = bfs.front();
                bfs.pop();
                if (node->right){
                    bfs.push(node->right);
                    localCount++;
                } 
                if (node->left){
                    bfs.push(node->left);
                    localCount++;
                }
                if (!isAddedList){
                    isAddedList = true;
                    ans.push_back(node->val);
                }
            }
            queueCount = localCount;
        }
        return ans;
    }
};
