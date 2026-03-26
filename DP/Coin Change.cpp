// Link - https://leetcode.com/problems/coin-change/description/

// Solution 1: Recursive approach

class Solution {
public:
    int rec(int idx, int amount, vector<int>& coins){

        if(idx == 0){
            if(amount % coins[idx] == 0){
                return amount/coins[idx];
            }else{
                return 1e9;
            }
        }

        int not_take = 0 + rec(idx-1, amount, coins);
        int take = INT_MAX;

        if(coins[idx] <= amount){
            take = 1 + rec(idx, amount-coins[idx], coins);
        }
        return min(not_take, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = rec(n-1, amount, coins);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

// Solution 2: Recursive approach with memoization

class Solution {
public:
    int rec(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp){

        if(idx == 0){
            if(amount % coins[idx] == 0){
                return amount/coins[idx];
            }else{
                return 1e9;
            }
        }

        if(dp[idx][amount] != -1){
            return dp[idx][amount];
        }

        int not_take = 0 + rec(idx-1, amount, coins, dp);
        int take = INT_MAX;

        if(coins[idx] <= amount){
            take = 1 + rec(idx, amount-coins[idx], coins, dp);
        }
        return dp[idx][amount] = min(not_take, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = rec(n-1, amount, coins, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};

