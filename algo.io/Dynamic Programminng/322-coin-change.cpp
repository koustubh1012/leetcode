class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);

        dp[0] = 0;

        for(int i = 0; i <= amount; i++){
            if(dp[i] == -1) continue;
            for(long int coin : coins){
                if((i + coin) <= amount){
                    if (dp[i+coin] == -1) dp[i+coin] = dp[i] + 1;
                    else dp[i+coin] = min(dp[i+coin], dp[i] + 1);
                }
            }
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[amount];
    }
};
