class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int lower_limit = intervals[0][0];
        int upper_limit = intervals[0][1];

        for(int i = 1; i < intervals.size(); i++){

            int current_lower = intervals[i][0];
            int current_upper = intervals[i][1];

            if(upper_limit < current_lower){
                ans.push_back({lower_limit, upper_limit});
                lower_limit = current_lower;
                upper_limit = current_upper;
            }
            if(lower_limit <= current_lower && upper_limit >= current_lower && upper_limit <= current_upper){
                upper_limit = current_upper;
            }
        }
        ans.push_back({lower_limit, upper_limit});
        return ans;
    }
};
