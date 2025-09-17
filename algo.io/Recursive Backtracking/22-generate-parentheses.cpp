class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string sol;
        backtrack(n, res, sol, 0, 0, 0);
        return res;
    }

private:
    void backtrack(int n, vector<string>& res, string& sol, int i, int num_open, int num_close){
        if(sol.size() == 2*n){
            res.push_back(sol);
            return;
        }

        if(num_open < n){
            sol.push_back('(');
            backtrack(n, res, sol, i+1, num_open + 1, num_close);
            sol.pop_back();
        }

        if(num_open > num_close){
            sol.push_back(')');
            backtrack(n, res, sol, i+1, num_open, num_close + 1);
            sol.pop_back();
        }
    }
};
