#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int max_profit = 0;
            int buy = INT_MAX;
            int profit = 0;
            for (int i=0; i<prices.size(); i++){
                buy = min(buy, prices[i]);
                profit = prices[i] - buy;
                max_profit = max(profit, max_profit);
            }
            return max_profit;
        }
    };

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl; // Output: 5
    return 0;
}