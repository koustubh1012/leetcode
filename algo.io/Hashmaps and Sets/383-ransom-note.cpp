#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            unordered_map<char, int> charCount;
            for (char c: magazine){
                charCount[c]++;
            }
            for (char c: ransomNote){
                if (charCount[c] > 0) {
                    charCount[c]--;
                } else {
                    return false;
                }
            }
            return true;
        }
    };

int main() {
    Solution sol;
    string ransomNote = "aa";
    string magazine = "aab";
    bool result = sol.canConstruct(ransomNote, magazine);
    cout << "\nCan construct ransom note: " << (result ? "true" : "false") << endl;
    return 0;
}