#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
    
            // Return false if the strings are unequal
            if(s.size() != t.size()) return false;
    
            // Create unordered map
            unordered_map<char, int> char_map;
            for(char c : s) char_map[c]++;
    
            // iterate characters of other strings
            for(char c : t){
    
                // check if a character does not exist
                if(char_map.find(c) == char_map.end()) return false;
    
                // decrement the charcter value from map and return false if already 0
                if(char_map[c] > 0) char_map[c]--;
                else return false;
            }
            return true;
        }
    };

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    bool result = sol.isAnagram(s, t);
    cout << "\nIs Anagram: " << (result ? "true" : "false") << endl;
    return 0;
}