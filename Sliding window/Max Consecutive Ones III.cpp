// link - https://leetcode.com/problems/max-consecutive-ones-iii/description/

// solution 1: using brute force

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;

        // iterate through the array and count the number of zeros in the current subarray
        for(int i=0; i<n; i++){
            int countZero = 0;
            int len = 0;
            for(int j=i; j<n; j++){
                len = j - i + 1;
                if(nums[j] == 0){
                    countZero++;
                }
                if(countZero > k){
                    break;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};

// solution 2: using sliding window approach

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int zeroCount = 0;
        int left = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0) zeroCount++;

            if(zeroCount > k){
                if(nums[left] == 0) zeroCount--;
                left++;
            }

            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};