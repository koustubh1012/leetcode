class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 1; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int L = i + 1;
            int R = nums.size() - 1;
            while(L < R){
                if(nums[L] + nums[R] + nums[i] == 0){
                    int L_val = nums[L];
                    int R_val = nums[R];
                    ans.push_back({nums[i], nums[L], nums[R]});
                    while(L < R && nums[L] == L_val) L++;
                    while(L < R && nums[R] == R_val) R--;
                }
                else if(nums[L] + nums[R] + nums[i] < 0) L++;
                else if(nums[L] + nums[R] + nums[i] > 0) R--;
            }
        }
        return ans;
    }
};
