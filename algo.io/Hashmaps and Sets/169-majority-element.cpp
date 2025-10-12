class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> dict;
        int max_freq = 0;
        int max_key;
        for(auto n : nums){
            dict[n]++;
        }
        for(auto& entry : dict){
            if(entry.second > max_freq){
                max_freq = entry.second;
                max_key = entry.first;
            }
        }
        return max_key;
    }
};
