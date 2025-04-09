#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
    
            //Return the complete string if its the only string
            if(strs.size() == 1) return strs[0];
    
            //Declare return string
            string prefix;
    
            // Loop through every character
            for (int i = 0; i < strs[0].size(); i++){
                // Loop through every word
                for (int j = 1; j < strs.size(); j++){
                    // check if the words are unequal
                    if (strs[j][i] != strs[0][i]) return prefix;
                }
                prefix += strs[0][i];
            }
            return prefix;
        }
    };

int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs) << endl; // Output: "fl"
    return 0;
}