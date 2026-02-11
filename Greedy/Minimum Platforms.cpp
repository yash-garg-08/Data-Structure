// link = https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Solution

class Solution {
    public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        int plat = 1;
        int maxi = 1;
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i=1;
        int j=0;
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                plat++;
                i++;
            }else{
                plat--;
                j++;
            }
            maxi = max(plat, maxi);
        }
        return maxi;
    }
};
