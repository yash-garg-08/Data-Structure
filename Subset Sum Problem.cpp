// Link - http://geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

// Solution: Memoization

class Solution {
    public:
    int dp[201][2001];
    bool rec(vector<int>& arr, int sum, int idx){
        if(sum == 0){
            return true;
        };
        if(idx == arr.size()){
            return false;
        }
        
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        
        if(arr[idx] > sum){
            return dp[idx][sum] = rec(arr, sum, idx+1);
        }
        //take
        bool take = rec(arr, sum - arr[idx], idx+1);
        // if(take) return true;
        bool not_take = rec(arr, sum, idx+1);
        return dp[idx][sum] = take || not_take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        // vector<vector<bool>> dp(n+1, vector<bool>(sum+1, -1));
        memset(dp, -1, sizeof(dp));
        return rec(arr, sum, 0);
    }
};