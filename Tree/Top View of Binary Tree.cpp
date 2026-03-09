// link - https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

// solution 1: using map and queue

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
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(root == NULL) return ans;
        
        // we will use a map to store the nodes according to their horizontal distance,
        // the key of the map will be the horizontal distance and the value will be the value of the node at that horizontal distance 
        // which will be the first node at that horizontal distance in the level order traversal of the tree
        map<int, int> mp;
        // we will use a queue to perform level order traversal of the tree 
        // and store the nodes in the map according to their horizontal distance
        queue<pair<Node*, int> > q;
        
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = frontNode->data;
            }
            
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