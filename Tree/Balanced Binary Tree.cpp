// link - https://leetcode.com/problems/balanced-binary-tree/description/

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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        bool leftCheck = isBalanced(root->left);
        bool rightCheck = isBalanced(root->right);

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight) <= 1;

        if(leftCheck && rightCheck && diff){
            return true;
        }else{
            return false;
        }
    }
};
// T.C. - O(n^2) - because for every node we are calculating height which is O(n) and there are n nodes

// solution 2: using pair to store height and balanced status

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
    pair<bool, int> isBalancedFast(TreeNode* root){

        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        pair<bool, int> leftCheck = isBalancedFast(root->left);
        pair<bool, int> rightCheck = isBalancedFast(root->right);

        int diff = abs(leftCheck.second - rightCheck.second) <= 1;
        
        pair<int, int>ans;
        if(leftCheck.first && rightCheck.first && diff){
            ans.first = true;
        }else{
            ans.first = false;
        }

        ans.second = max(leftCheck.second, rightCheck.second) + 1;
        return ans;

    }

    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};

// T.C. - O(n) - because we are calculating height and balanced status in one traversal