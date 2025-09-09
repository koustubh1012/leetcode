class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector to store the total const at each step
        int n = cost.size();
        if(n == 2) return 0;

        vector<int> total_cost(n+1);
        total_cost[0] = 0;
        total_cost[1] = 0;

        // loop to calculate the cost at each step
        for(int i = 2; i <= n; i++){
            total_cost[i] = min(total_cost[i-1] + cost[i-1], total_cost[i-2] + cost[i-2]);
        }

        return total_cost[n];
    }
};
