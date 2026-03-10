// link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

// solution 1: using recursion

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        // if the value of the root node is equal to the value of p or q
        // then we will return the root node because it can be the lowest common ancestor of p and q
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL){
            return root;
        }else if(left != NULL && right == NULL){
            return left;
        }else if(left == NULL && right != NULL){
            return right;
        }else{
            return NULL;
        }
    }
};