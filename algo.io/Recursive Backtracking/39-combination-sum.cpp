class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sol;
        backtrack(candidates, target, sol, res, 0, 0);
        return res;
    }
private:
    void backtrack(vector<int>& candidates, int target,vector<int>& sol, vector<vector<int>>& res, int start, int curr_sum){
        if (curr_sum == target) {
            res.push_back(sol);
            return;
        }
        if (curr_sum > target || start >= candidates.size()) {
            return;
        }
        backtrack(candidates, target, sol, res, start + 1, curr_sum);
        sol.push_back(candidates[start]);
        curr_sum = curr_sum + candidates[start];
        backtrack(candidates, target, sol, res, start, curr_sum);
        sol.pop_back();
    }
};
