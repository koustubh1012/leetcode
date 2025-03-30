#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> seen;
            for (int num : nums){
                if(seen.find(num)!=seen.end()){
                    return true;
                }
                seen.insert(num);
            }
            return false;
        }
    };

int main() {   
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};
    bool result = sol.containsDuplicate(nums);
    cout << "Contains duplicate: " << (result ? "true" : "false") << endl;
    return 0;
}