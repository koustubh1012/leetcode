class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        vector<bool> used(nums.size(), false);
        backtrack(nums, sol, res, used);
        return res;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& sol, vector<vector<int>>& res, vector<bool>& used){
        if(sol.size() == nums.size()){
            res.push_back(sol);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            sol.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, sol, res, used);
            sol.pop_back();
            used[i] = false;
        }
    }
};
