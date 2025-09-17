class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string sol;
        unordered_map<char, vector<char>> dict;
        dict['2'] = {'a','b','c'};
        dict['3'] = {'d','e','f'};
        dict['4'] = {'g','h','i'};
        dict['5'] = {'j','k','l'};
        dict['6'] = {'m','n','o'};
        dict['7'] = {'p','q','r','s'};
        dict['8'] = {'t','u','v'};
        dict['9'] = {'w','x','y','z'};

        if(digits.size() == 0) return res;

        backtrack(digits, res, sol, dict, 0);

        return res;
    }
private:
    void backtrack(string digits, vector<string>& res, string& sol, unordered_map<char, vector<char>>& dict,int start){
        if(sol.size() == digits.size()){
            res.push_back(sol);
            return;
        }

        for(char c : dict[digits[start]]){
            sol.push_back(c);
            backtrack(digits, res, sol, dict, start+1);
            sol.pop_back();
        }
    }
};
