//link - https://leetcode.com/problems/combination-sum-ii/description/

// solution 1: Recursive approach

class Solution {
public:
    void rec(vector<int>& candidates, int target, int idx, vector<int>& arr, vector<vector<int>>& res){
        if(target < 0){
            return;
        }
        if(target == 0){
            res.push_back(arr);
        }

        for(int i=idx; i < candidates.size(); i++){
            // to skip duplicates
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;

            //take
            arr.push_back(candidates[i]);
            rec(candidates, target-candidates[i], i+1, arr, res);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> arr;
        vector<vector<int>> res;

        sort(candidates.begin(), candidates.end());

        rec(candidates, target, 0, arr, res);

        return res;
    }
};