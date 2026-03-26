class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        int first_dec = -1;

        //traverse from the left to find the index of first descending number
        //example '4' in number '1549873' has index 2
        for(int i = n-1; i > 0; i--){
            if(nums[i-1] < nums[i]){
                first_dec = i-1;
                break;
            }
        }

        //if no number is in desc. order then reverse the whole array
        if(first_dec != -1){

            int swap_index = first_dec;
            //traverse from the right to find the index of the just bigger number
            //from the first_dec number
            for(int j = n-1; j > first_dec; j--){
                if(nums[j] > nums[first_dec]){
                    swap_index = j;
                    break;
                }
            }

            //swap thode two numbers
            swap(nums[first_dec], nums[swap_index]);
        }

        //reverse after swapping
        reverse(nums.begin() + first_dec + 1, nums.end());

    }
};
