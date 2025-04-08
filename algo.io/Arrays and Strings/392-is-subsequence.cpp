#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int count = 0;
            int i = 0;
            for (char x: t){
                if (s[i] == x){
                    count++;
                    i++;
                }
            }
            if (count == s.size()) return true;
            else return false;
        }
    };

int main() {
    Solution sol;
    string s = "abc";
    string t = "ahbgdc";
    cout << sol.isSubsequence(s, t) << endl; // Output: 1 (true)
    return 0;
}