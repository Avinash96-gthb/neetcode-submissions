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

 // since it is a bst there are three possibilities
 // current node is between p and q, in which case it is the lowest common ancestor
 // the current node is lesser than p and q in which case the lowest ancestor is probably in the right
 // the current node is greater than both in which case the ancestor is to the left

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root){
            return nullptr;
        }
        if ((p->val <= root->val && root->val <= q->val) ||
    (q->val <= root->val && root->val <= p->val)){
            return root;
        }
        if (root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val << p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
    }
};
