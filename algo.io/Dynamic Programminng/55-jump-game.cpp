class Solution {
public:
    bool canJump(vector<int>& nums) {
        // get size of array
        int n = nums.size();

        if(n==1) return true;

        else if(nums[0] == 0) return false;

        // vector to store the number of jumps remaining from each point
        vector<int> rem_jumps(n,0);

        // intialise first jump
        rem_jumps[0] = nums[0];

        // loop to iterate through the numbers
        for(int i = 1; i < n - 1; i++){
            int avail_jumps = max(rem_jumps[i-1] - 1, nums[i]);
            rem_jumps[i] = avail_jumps;
            if (avail_jumps <= 0) return false; 
        }
        return true;
    }
};
