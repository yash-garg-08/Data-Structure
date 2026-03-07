// link - https://leetcode.com/problems/same-tree/description/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }else if(p == NULL && q != NULL){
            return false;
        }else if(p != NULL && q == NULL){
            return false;
        }

        bool leftCHeck = isSameTree(p->left, q->left);
        bool rightCheck = isSameTree(p->right, q->right);

        bool valMatch = p->val == q->val;

        if(leftCHeck && rightCheck && valMatch){
            return true;
        }else{
            return false;
        }

    }
};

// T.C. - O(n) - because we are visiting every node once
// S.C. - O(n) - because of recursion stack in worst case when tree is skewed