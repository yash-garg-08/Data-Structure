// link - https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

//solution 1: binary search

class Solution {
  public:
    int checkRoot(int mid, int n){
        if(n == 0) return 1;
        return mid * checkRoot(mid, n-1);
    }
    int nthRoot(int n, int m) {
        // Code here
        if(m==0) return 0;
        int low = 1;
        int high = m;
        
        while( low <= high){
            int mid = (low+high)/2;
            int rootVal = checkRoot(mid, n);
            if(rootVal == m){
                return mid;
            }else if(rootVal < m){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};
