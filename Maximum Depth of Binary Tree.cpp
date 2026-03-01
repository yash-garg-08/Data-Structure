// link - https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

// solution 1: using recursion

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
    int calHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(calHeight(root->left), calHeight(root->right));
    }
    int maxDepth(TreeNode* root) {
        int height = 0;
        height = calHeight(root);
        return height;
    }
};