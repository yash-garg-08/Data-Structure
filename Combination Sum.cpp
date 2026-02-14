// link - https://leetcode.com/problems/combination-sum/description/

// Solution 1: Recursive approach

class Solution {
public:
    void rec(vector<int>& candidates, int target, int idx, vector<int> arr, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(arr);
            return;
        }
        if(idx == candidates.size()){
            return;
        }

        //not take
        rec(candidates, target, idx+1, arr, res);

        //take
        if(target >= candidates[idx]){
            arr.push_back(candidates[idx]);
            rec(candidates, target-candidates[idx], idx, arr, res);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;
        rec(candidates, target, 0, arr, res);
        return res;
    }
};