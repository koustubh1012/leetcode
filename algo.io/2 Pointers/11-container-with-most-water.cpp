class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int ans = 0;
        while(L < R){
            int L_height = height[L];
            int R_height = height[R];
            int current_level = min(L_height, R_height) * (R - L);
            ans = max(ans, current_level);
            if(L_height < R_height) L++;
            else R--;
        }
        return ans;
    }
};
