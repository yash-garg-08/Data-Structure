// link - https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

//solution 1: using brute force

class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> arr;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr.push_back(mat[i][j]);
            }
        }
        
        sort(arr.begin(), arr.end());
        
        int mid_el = arr.size();
        mid_el = mid_el/2;
        
        return arr[mid_el];
        
    }
};

// solution 2: using binary search

class Solution {
  public:
    int numLessOrEqualToMid(int mid, vector<int> row){
        return upper_bound(row.begin(), row.end(), mid) - row.begin();
    }
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i<n; i++){
            mini = min(mini, mat[i][0]);
            maxi = max(maxi, mat[i][m-1]);
        }
        
        int left = mini;
        int right = maxi;
        
        while(left<=right){
            int mid = (left+right)/2;
            
            int count = 0;
            for(int i=0; i<n; i++){
                count += numLessOrEqualToMid(mid, mat[i]);
            }
            
            if(count < ((m*n)+1)/2){
                left = mid+1;
            }else{
                right = right-1;
            }
        }
        return left;
        
    }
};
