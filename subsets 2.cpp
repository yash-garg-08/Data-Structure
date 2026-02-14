// link - https://leetcode.com/problems/subsets-ii/

// solution 1: Recursive approach

class Solution {
public:
    void rec(vector<int>& nums, int idx, vector<int> arr, set<vector<int>>& res){
        if(idx == nums.size()){
            // sorting the array to avoid duplicate subsets like [1,2] and [2,1] which converts them into same subset [1,2]
            sort(arr.begin(), arr.end());
            res.insert(arr);
            return;
        }

        //not take
        rec(nums, idx+1, arr, res);

        //take
        arr.push_back(nums[idx]);
        rec(nums, idx+1, arr, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> arr;
        // using set to avoid duplicate subsets
        set<vector<int>> res;

        rec(nums, 0, arr, res);

        vector<vector<int>> vector_res;
        for(auto &it : res){
            vector_res.push_back(it);
        }
        return vector_res;
    }
};