#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int L = 0;
            int R = nums.size() - 1;
            int mid;
            while (L <= R){
                mid = L + (R - L)/2;
                if (nums[mid] ==  target){
                    return mid;
                }
                else if (target < nums[mid]){
                    R = mid -1;
                }
                else{
                    L = mid + 1;
                }
            }
            if (nums[mid] < target){
                return mid + 1;
            }
            else{
                return mid;
            }
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {1,3,5,6};
    int target = 2;
    int result = sol.searchInsert(nums, target);
    cout << "\nIndex of target: " << result << endl;
    return 0;
}