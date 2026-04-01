// link - https://leetcode.com/problems/climbing-stairs/description/

// solution 1: using recursion
int climbStairs(int n) {
    if(n <= 2) return n;
    return climbStairs(n-1) + climbStairs(n-2);
}

// Time Complexity: O(2^n) - Exponential time complexity due to the repeated calculations of the same subproblems.
// Space Complexity: O(n) - The maximum depth of the recursion stack can go up to n.

// solution 2: using memoization
class Solution {
public:
    int t[46];
    int solve(int n){
        if(n < 0){
            return 0;
        }
        if(t[n] != -1) return t[n];
        if(n == 0){
            return 1;
        }
        return t[n] = solve(n-1) + solve(n-2);
    }

    int climbStairs(int n) {
        if(n <= 2) return n;

       memset(t, -1, sizeof(t));

        solve(n);

        return t[n];
    }
};

// Time Complexity: O(n) - Each subproblem from 0 to n is calculated only once and stored in the t array.
// Space Complexity: O(n) - The t array of size 46 is used to store the results of subproblems, and the recursion stack can go up to n in the worst case.

// solution 3: using tabulation
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;

        int a = 1;
        int b = 2;
        int c = 0;

        for(int i=3; i<=n; i++){
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
};

// Time Complexity: O(n) - Each subproblem from 3 to n is calculated once in a bottom-up manner.
// Space Complexity: O(1) - Only a constant amount of space is used to store the last two computed values (a and b) and the current value (c).