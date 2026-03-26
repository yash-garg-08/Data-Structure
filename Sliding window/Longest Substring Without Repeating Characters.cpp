// link - https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

// solution 1: using hash map brute force approach

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            // create a hash map to store the characters in the current substring
            vector<int> hash(256, 0);
            for(int j=i; j<n; j++){
                // if the character is already present in the hash map, break the loop
                if(hash[s[j]] == 1){
                    break;
                }
                hash[s[j]] = 1;
                int len = j-i+1;
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};

// solution 2: using sliding window approach

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // create a hash map to store the index of the characters in the current substring
        vector<int> hash(256, -1);
        int l = 0, r = 0, maxLen = 0;
        while(r < n){
            // if the character is already present in the hash map,
            // move the left pointer to the right of the previous index of the character
            if(hash[s[r]] != -1){
                l = max(hash[s[r]] + 1, l);
            }
            int len = r - l + 1;
            maxLen = max(maxLen, len);
            // update the index of the character in the hash map
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};