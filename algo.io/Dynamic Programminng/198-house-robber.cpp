class Solution {
public:
    int rob(vector<int>& nums) {

        // get the size of nums vector
        int n = nums.size();

        // handle edge cases
        if(n == 1) return nums[0];
        else if(n == 2) return max(nums[0], nums[1]);

        // vector to store total amount of roberies till each house
        vector<int> total(nums.size());

        // vector to store the values of first two elements
        total[0] = nums[0];
        total[1] = max(nums[0], nums[1]);

        // loop to iterate through each house
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] + total[i-2] > total[i-1]){
                total[i] = total[i-2] + nums[i];
            }
            else{
                total[i] = total[i-1];
            }
        }

        return total[n-1];
    }
};
