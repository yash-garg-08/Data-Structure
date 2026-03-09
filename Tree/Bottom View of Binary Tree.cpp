// link - https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// solution 1: using map and queue

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // we will update the value of the node at that horizontal distance in the map according to the level order traversal of the tree
            // last node at that horizontal distance in the level order traversal of the tree will be the bottom view of the tree at that horizontal distance
            mp[hd] = frontNode->data;
            if(frontNode->left){
                q.push(make_pair(frontNode->left, hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right, hd+1));
            }
        }
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};