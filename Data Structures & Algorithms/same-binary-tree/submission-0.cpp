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
    bool isIdentical = true;
    int checkEveryNode(TreeNode* p, TreeNode* q){
        if (!p && !q){
            return 0;
        }
        if (!p || !q){
            isIdentical = false;
            return 0;
        }
        if (p->val != q->val){
            isIdentical = false;
        }
        int left = checkEveryNode(p->left, q->left);
        int right = checkEveryNode(p->right, q->right);
        return 1 + max(left, right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q){
            return true;
        }
        if (!p || !q){
            return false;
        }

        int val = checkEveryNode(p,q);
        return isIdentical;

    }
};
