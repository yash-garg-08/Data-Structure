// Link - https://leetcode.com/problems/subsets/

// solution 1: Recursive approach

class Solution {
public:
    void rec(vector<int>& nums, int idx, vector<int> arr, vector<vector<int>> &res){
        if(idx == nums.size()){
            res.push_back(arr);
            return;
        }
        // not take
        rec(nums, idx+1, arr, res);
        
        // take
        arr.push_back(nums[idx]);
        rec(nums, idx+1, arr, res);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> arr;
        rec(nums, 0, arr, res);
        return res;
    }
};