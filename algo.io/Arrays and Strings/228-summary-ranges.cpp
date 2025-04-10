#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> result;
    
            // Handle edge case
            if (nums.size() == 0) return result;
    
            // initialise first range start
            int start = nums[0];
    
            // Iterate through the nums vector
            for(int i=1; i<=nums.size(); i++){
    
                // Check if it's the last element or the current range has ended
                if(i == nums.size() || nums[i] != nums[i-1] + 1){
    
                    // check if it's only a one element range
                    if (start == nums[i-1]){
                        result.push_back(to_string(start));
                    } 
    
                    // push back the current range
                    else{
                        result.push_back(to_string(start)+"->"+to_string(nums[i-1]));
                    }
    
                    // update the start variable if it's not the end of vector nums
                    if (i<nums.size()) start = nums[i];
                }
            }
            return result;
        }
    };

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 2, 4, 5, 7};
    vector<string> result = sol.summaryRanges(nums);
    
    for (const string& range : result) {
        cout << range << " ";
    }
    return 0;
}