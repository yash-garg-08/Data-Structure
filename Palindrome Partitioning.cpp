// link - https://leetcode.com/problems/palindrome-partitioning/description/

// solution 1: backtracking

class Solution {
public:
    int n;
    bool isPalindrome(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void rec(string& s, int idx, vector<string> arr, vector<vector<string>>& res){
        if(idx == n){
            res.push_back(arr);
            return;
        }
        for(int i=idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                arr.push_back(s.substr(idx, i-idx+1));
                rec(s, i+1, arr, res);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> arr;
        vector<vector<string>> res;

        rec(s, 0, arr, res);
        return res;
    }
};