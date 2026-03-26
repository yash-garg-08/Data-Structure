#include <bits/stdc++.h> 
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        if(n == 0) return true;

        string ans = "";

        //for conver into lowercase
        for(auto& j: s){
            j = tolower(j);
        }

        //for removing all non alphanumeric charcters
        for(int i = 0; i < n; i++){
            if(int(s[i]) >= 97  && int(s[i]) <= 122){
                ans += s[i];
            }else if(int(s[i]) >= 48 && int(s[i]) <= 57 ){
                ans += s[i];
            }
        }
        
        //for checking palindrome
        int i = 0;
        int j = ans.size()-1;

        while(i <= j){
            if(ans[i] != ans[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
};
