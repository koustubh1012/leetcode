class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // initlaise result
        vector<int> res(nums.size(), 1);

        int left_prod = 1;
        int right_prod = 1;

        // calculate left digits multiplication
        for(int i = 0; i < nums.size(); i++){
            res[i] = left_prod;
            left_prod *= nums[i];
        }

        // calculate right digits multiplication
        for(int i = nums.size() - 1; i >= 0; i--){
            res[i] *= right_prod;
            right_prod *= nums[i];  
        }

        return res;
    }
};
