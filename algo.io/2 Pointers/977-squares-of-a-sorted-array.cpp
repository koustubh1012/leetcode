#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n = nums.size();
            int L = 0;
            int R = n - 1;
            vector<int> result(n);
            int i = 0;
            while (L <= R){
                if (nums[L]*nums[L] < nums[R]*nums[R]){
                    result[n-1-i] = nums[R]*nums[R];
                    R--;
                }
                else{
                    result[n-1-i] = nums[L]*nums[L];
                    L++;
                }
                i++;
            }
            return result;
        }
    };
int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sol.sortedSquares(nums);
    cout << "Sorted squares: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}