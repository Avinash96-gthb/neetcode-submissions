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
    bool correct = false;
    bool isSimilar(TreeNode* main, TreeNode* sub){
        if (!main && !sub){
            return true;
        }
        // if (!main && sub){
        //     return false;
        // }
        // if (main && !sub){
        //     return true;
        // }
        if (main && sub && main->val == sub->val){
            return isSimilar(main->left, sub->left) && isSimilar(main->right, sub->right);
        } else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot){
            return true;
        }
        if (!root){
            return false;
        }
        bool similarity = isSimilar(root, subRoot);
        if (similarity){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
