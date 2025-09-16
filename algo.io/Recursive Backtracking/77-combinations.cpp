class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> sol;
        vector<vector<int>> res;
        backtrack(n, k, sol, res, 1);
        return res;
    }
private:
    void backtrack(int n, int k, vector<int>& sol, vector<vector<int>>& res, int start){
        if(sol.size() == k){
            res.push_back(sol);
            return;
        }
        for(int i = start; i <= n; i++){

            sol.push_back(i);

            backtrack(n, k, sol, res, i + 1);

            sol.pop_back();
        }
    }
};
