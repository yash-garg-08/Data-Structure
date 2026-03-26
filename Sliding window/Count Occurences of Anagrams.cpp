// link - https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

// solution 1: using brute force approach
// User function template for C++
class Solution {
  public:
    bool checkAnagram(string pat, string txt){
        if(pat.length() != txt.length()) return false;
        
        unordered_map<char, int> mp;
        
        for(char i:pat){
            mp[i] += 1;
        }
        
        for(char i: txt){
            mp[i] -= 1;
        }
        
        for(auto pair: mp){
            if(pair.second != 0) return false;
        }
        return true;
    }
    int search(string &pat, string &txt) {
        // code here
        int n = pat.length();
        int i = 0;
        int j = n-1;
        int count = 0;
        while(j < txt.length()){
            string sub = txt.substr(i, n);
            if(checkAnagram(pat, sub)) count++;
            i++;
            j++;
        }
        return count;
    }
};

// Time Complexity: O(N * M) where N is the length of the text and M is the length of the pattern
// Space Complexity: O(M)

// solution 2: using sliding window approach

// User function template for C++
class Solution {
  public:
    bool checkAnagram(vector<int> counter){
        for(auto& i: counter){
            if(i != 0) return false;
        }
        return true;
    }
    int search(string &pat, string &txt) {
        // code here
        int n = pat.length();
        int k = txt.length();
        int i = 0, j = 0;
        int count = 0;
        vector<int> counter(26, 0);
        for(int i=0; i<n; i++){
            char c = pat[i];
            counter[c - 'a']++;
        }
        while(j < k){
            counter[txt[j] - 'a']--;
            if(n == j - i + 1){
                if(checkAnagram(counter)) count++;
                counter[txt[i] - 'a']++;
                i++;
            }
            j++;
        }
        return count;
    }
};