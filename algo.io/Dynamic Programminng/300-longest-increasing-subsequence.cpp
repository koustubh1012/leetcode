class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);

        int max_len = 0;

        if(nums.size() == 1) return 1;
        
        for(int i = 1; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            max_len = max(dp[i], max_len);
        }
        return max_len;
    }
};
