// link - https://leetcode.com/problems/house-robber/description/

// solution 1: using recursion

class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums, int i, int n){
        if(i >= n){
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int take = nums[i] + solve(nums, i+2, n);
        int not_take = solve(nums, i+1, n);

        return dp[n] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof(dp));
        return solve(nums, 0, n);
    }
};

// solution 2: using tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        vector<int> dp(n+1, 0);
        dp[1] = nums[0];

        for(int i=2; i<=n; i++){
            // dp[i-1] - not taking the current house
            // nums[i-1] + dp[i-2] - taking the current house and adding the maximum amount from two houses back
            // (max amount upto house i will be stored in dp[i] so max of prev of prev house will be stored in dp[i-2])
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};