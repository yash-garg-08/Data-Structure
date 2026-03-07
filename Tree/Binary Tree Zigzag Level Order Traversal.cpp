// link - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

// solution 1: using queue

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        // we will use a boolean variable to keep track of the direction of traversal, 
        // if it is true then we will traverse from left to right 
        // and if it is false then we will traverse from right to left
        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> tempArr(size);

            // we will traverse the current level and push the values of the nodes in tempArr according to the direction of traversal
            for(int i=0; i<size; i++){

                TreeNode* temp = q.front();
                q.pop();

                // if leftToRight is true then we will push the value of the node at index i in tempArr
                // otherwise we will push the value of the node at index size - i - 1 in tempArr
                int index = leftToRight ? i : size - i - 1;
                tempArr[index] = temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(tempArr);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};

// T.C. - O(n) - because we are visiting every node once
// S.C. - O(n) - because of the queue and the answer vector which can store all the nodes in the worst case when the tree is complete binary tree