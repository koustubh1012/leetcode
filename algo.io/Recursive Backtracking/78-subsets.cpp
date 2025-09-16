class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;   
        backtrack(nums, sol, res, 0);
        return res;
    }
private:
    void backtrack(vector<int>& nums, vector<int>& sol, vector<vector<int>>& res, int start){
        if(start == nums.size()){
            res.push_back(sol);
            return;
        }
        backtrack(nums, sol, res, start + 1);
        sol.push_back(nums[start]);
        backtrack(nums, sol, res, start + 1);
        sol.pop_back();
    }
};
