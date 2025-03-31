#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int L = 0;
            int R = nums.size() - 1;
            while(L<=R){
                int mid = L + (R - L)/2;
                if(nums[mid] == target){
                    return mid;
                }
                else if(target < nums[mid]){
                    R = mid - 1;
                }
                else{
                    L = mid + 1;
                }
            }
            return -1;

        }
    };
int main() {
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int result = sol.search(nums, target);
    cout << "\nIndex of target: " << result << endl;
    return 0;
}