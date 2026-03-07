// link - https://www.geeksforgeeks.org/problems/sum-tree/1

// solution 1: using recursion

/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
    public:
    
    pair<int, bool> isSumTreeCheck(Node* root){
        if(root == NULL){
            return {0, true};
        }
        if(root->left == NULL && root->right == NULL) {
            return {root->data, true};
        }
        
        pair<int, bool> leftPair = isSumTreeCheck(root->left);
        pair<int, bool> rightPair = isSumTreeCheck(root->right);

        if((leftPair.first + rightPair.first == root->data) && leftPair.second && rightPair.second){

            //returning the sum of the subtree rooted at current node 
            //which is equal to the value of the current node + sum of left subtree + sum of right subtree
            return {root->data + leftPair.first + rightPair.first, true};
        }
        return {0, false};
    }

    bool isSumTree(Node* root) {
        // Your code here
        if(root == NULL) return true;
        return isSumTreeCheck(root).second;
    }
};