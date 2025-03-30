#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        void reverseString(vector<char>& s) {
            int L = 0;
            int R = s.size() - 1;
            while (L <= R){
                swap(s[L++], s[R--]);
            }
        }
    };

int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s);
    cout << "Reversed string: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;
    return 0;
}