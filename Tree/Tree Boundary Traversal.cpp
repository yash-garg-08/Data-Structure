// link - https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// solution 1: using recursion

// Approach - 
// We will traverse the left boundary of the tree and store the nodes in the answer vector except the leaf nodes because we will traverse the leaf nodes separately and store them in the answer vector, 
// then we will traverse the leaf nodes and store them in the answer vector 
// and finally we will traverse the right boundary of the tree and store the nodes in the answer vector in reverse order.

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverseLeft(Node* root, vector<int>& ans){
        if( (root == NULL) || (root->left == NULL && root->right == NULL) ) return;
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseLeft(root->left, ans);
        }else{
            traverseLeft(root->right, ans);
        }
    }
    void traverseLeaf(Node* root, vector<int>& ans){
        if(root == NULL) return;
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    void traverseRight(Node* root, vector<int>& ans){
        if( (root == NULL) || (root->left == NULL && root->right == NULL) ) return;
        
        if(root->right){
            traverseRight(root->right, ans);
        }else{
            traverseRight(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        ans.push_back(root->data);
        
        traverseLeft(root->left, ans);
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        
        traverseRight(root->right, ans);
        
        return ans;
    }
};

// T.C. - O(n) - because we are visiting every node once
// S.C. - O(n) - because of the answer vector which can store all the nodes in the worst case when the tree is a skewed tree