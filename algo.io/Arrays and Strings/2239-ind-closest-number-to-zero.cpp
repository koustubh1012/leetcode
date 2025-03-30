#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int findClosestNumber(vector<int>& nums) {
            long int dist = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (abs(nums[i]) < abs(dist)){
                    dist = nums[i];
                } else if (abs(nums[i]) == abs(dist)) {
                    if (nums[i] > dist) {
                        dist = nums[i];
                    }
                }
            }
            return dist;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {-10,-12,-54,-12,-544,-10000};
    int result = sol.findClosestNumber(nums);
    cout << "The closest number to zero is: " << result << endl;
    return 0;
}