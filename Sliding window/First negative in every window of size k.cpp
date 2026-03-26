// link - https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// solution 1: using brute force approach

class Solution {
  public:
    int findFirstNeg(vector<int> arr, int i, int j){
        for(int k=i; k<=j; k++){
            if(arr[k] < 0) return arr[k];
        }
        return 0;
    }
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> res;
        int i = 0, j = k-1;
        int n = arr.size();
        
        while(j < n){
            int temp = findFirstNeg(arr, i, j);
            res.push_back(temp);
            i++;
            j++;
        }
        return res;
    }
};

// solution 2: using deque

class Solution {
  public:
    
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> res;
        int i = 0, j = 0;
        deque<int> dq;
        int n = arr.size();
        
        while(j < n){
            if(arr[j] < 0){
                dq.push_back(arr[j]);
            }
            if(j - i + 1 == k){
                if(!dq.empty()){
                    res.push_back(dq.front());
                }else{
                    res.push_back(0);
                }
                if(arr[i] < 0 && !dq.empty()){
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return res;
    }
};