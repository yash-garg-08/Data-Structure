// link - https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(root == NULL) return ans;

        // store the nodes of the tree according to their level in the map,
        // the key of the map will be the level and the value will be the value of the node at that level 
        // which will be the last node at that level in the level order traversal of the tree
        map<int, int> mp;
        queue<pair<TreeNode*, int> > q;

        q.push({root, 0});

        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int lvl = temp.second;

            if(mp.find(lvl) == mp.end()){
                mp[lvl] = frontNode->val;
            }

            if(frontNode->right){
                q.push(make_pair(frontNode->right, lvl+1));
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left, lvl+1));
            }
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};