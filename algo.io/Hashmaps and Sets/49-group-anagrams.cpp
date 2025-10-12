class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;

        unordered_map<string, vector<string>> dict;

        for(auto str : strs){
            string key = str;
            sort(key.begin(), key.end());
            dict[key].push_back(str);
        }

        for(auto& entry : dict){
            ans.push_back(entry.second);
        }

        return ans;
    }
};
