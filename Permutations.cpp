// Link - https://leetcode.com/problems/permutations/

// solution 1: backtracking

class Solution {
public:
    // final result vector
    vector<vector<int>> res;
    // used to keep track of the elements in the current permutation
    unordered_set<int> st;
    int n;
    void rec(vector<int>& nums, vector<int>& temp){
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++){
            // If the element is not already in the current permutation then we can select it
            if(st.find(nums[i]) == st.end()){
                // Select
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                // Explore
                rec(nums, temp);
                //Remove
                temp.pop_back();
                st.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        n = nums.size();
        rec(nums, temp);
        return res;
    }
};