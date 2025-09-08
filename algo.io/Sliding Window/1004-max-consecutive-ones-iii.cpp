class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // create a Left pounter and zero counter
        int L = 0;
        int count = 0;
        int max_ones = 0;

        // iterate through the numbers 
        for(int R = 0; R < nums.size(); R++){
            // check if the current nuber is zero
            if(nums[R] == 0){
                count++;
            }

            // make the window valid
            while(count > k){
                if(nums[L] == 0){
                    count--;
                }
                L++;
            }
            max_ones = max(max_ones, R - L + 1);
        }
        return max_ones;
    }
};
