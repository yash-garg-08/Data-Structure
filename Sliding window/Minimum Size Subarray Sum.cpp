// link - https://leetcode.com/problems/minimum-size-subarray-sum/

// solution 1: using sliding window approach

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int minLen = INT_MAX;
        while(j < n){
            sum = sum + nums[j];
            // if the sum is greater than or equal to the target,
            // move the left pointer to the right and update the minimum length of the subarray
            while(sum >= target){
                minLen = min(minLen, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};