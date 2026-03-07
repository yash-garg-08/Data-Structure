// link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

// solution 1: using map and queue

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        // we will use a map to store the nodes according to their horizontal distance and level,
        // the key of the outer map will be the horizontal distance and the value will be another map which will store the nodes according to their level, 
        // the key of the inner map will be the level and the value will be a vector which will store the values of the nodes at that level and horizontal distance
        map<int, map<int, vector<int> > > mp;
        // we will use a queue to perform level order traversal of the tree 
        // and store the nodes in the map according to their horizontal distance and level
        queue<pair<TreeNode*, pair<int, int> > > q;

        q.push(make_pair(root, make_pair(0,0)));

        while(!q.empty()){

            pair<TreeNode*, pair<int, int> > temp = q.front();
            q.pop();

            // we will get the front node and its horizontal distance and level from the queue
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            // we will push the value of the front node in the map according to its horizontal distance and level
            mp[hd][lvl].push_back(frontNode->val);

            // we will push the left and right children of the front node in the queue with their horizontal distance and level
            if(frontNode->left){
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
            }

        }

        // we will traverse the map and push the values of the nodes in the answer vector according to their horizontal distance and level
        for(auto i: mp){
            vector<int> tempArr;
            for(auto j: i.second){
                // we will sort the values of the nodes at the same level and horizontal distance in ascending order before pushing them in the answer vector
                sort(j.second.begin(), j.second.end());
                tempArr.insert(tempArr.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(tempArr);
        }
        return ans;
    }
};

// T.C. - O(n log n) - because we are sorting the values of the nodes at each level and there can be at most n nodes at a level in the worst case when the tree is skewed
// S.C. - O(n) - because of the map and the queue which can store all the nodes in the worst case when the tree is complete binary tree