// link - https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

// solution 1: using queue

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;

        if(root == NULL) return ans;

        map<int, int> mp;
        queue<pair<Node*, int> > q;

        q.push({root, 0});

        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int lvl = temp.second;

            // we will push the value of the front node in the map according to its level
            // first node at that level in the level order traversal of the tree will be the left view of the tree at that level
            // if(mp.find(lvl) == mp.end()){
                mp[lvl] = frontNode->data;
            // }

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