#include <iostream>
#include <string>
using namespace std;

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            int n1 = word1.size();
            int n2 = word2.size();
            string merged_string;
            int min_length = min(n1, n2);
            for(int i=0; i<min_length; i++){
                merged_string += word1[i];
                merged_string += word2[i];
            }
            if (n1 > n2){
                string remaining(word1.begin() + min_length, word1.end());
                merged_string += remaining;
            }
            else{
                string remaining(word2.begin() + min_length, word2.end());
                merged_string += remaining;
            }
            return merged_string;
        }
    };

int main() {   
    Solution sol;
    string word1 = "abcdef";
    string word2 = "pqr";
    string result = sol.mergeAlternately(word1, word2);
    cout << "Merged string: " << result << endl;
    return 0;
}