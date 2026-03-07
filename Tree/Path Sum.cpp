// link - https://leetcode.com/problems/path-sum/description/

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        //case when root is null or tree is empty
        if(root == NULL) return false;

        //case when we are at leaf node, we will check if the target sum is equal to the value of the leaf node, 
        // if yes then we have found a path and we will return true otherwise false
        if(root->left == NULL && root->right == NULL){
            return targetSum == root->val;
        }

        // we will check for left and right subtrees by reducing the target sum by the value of the current node
        bool leftCheck = hasPathSum(root->left, targetSum - root->val);
        bool rightCheck = hasPathSum(root->right, targetSum - root->val);

        // if either leftCheck or rightCheck is true then we have found a path and we will return true otherwise false
        return leftCheck || rightCheck;
    }
};