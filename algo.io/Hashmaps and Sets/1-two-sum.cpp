class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++){
            map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int y = target - nums[i];
            if (map.find(y) != map.end() && map[y]!=i){
                return vector<int>{i, map[y]} ;
            }
        }
        throw invalid_argument("No two sum solution");
    }
};
