// link - https://leetcode.com/problems/fibonacci-number/description/

// solution 1: using recursion
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

// Time Complexity: O(2^n) - Exponential time complexity due to the repeated calculations of the same Fibonacci numbers.
// Space Complexity: O(n) - The maximum depth of the recursion stack can go up to

// solution 2: using memoization
class Solution {
public:
    int solve(vector<int>& dp, int n){
        if(n <= 1){
            dp[n] = n;
        }
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(dp, n-1) + solve(dp, n-2);
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        solve(dp, n);
        return dp[n];
    }
};

// Time Complexity: O(n) - Each Fibonacci number from 0 to n is calculated only once and stored in the dp array.
// Space Complexity: O(n) - The dp array of size n+1 is used to

