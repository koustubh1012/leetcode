#include <iostream>

using namespace std;

class Solution {
    public:
        bool isPerfectSquare(int num) {
            long int L = 0;
            long int R = num;
            long int mid;
            while (L <= R){
                mid = L + (R - L) / 2;
                if (mid*mid == num){
                    return true;
                }
                else if (mid*mid > num){
                    R = mid - 1;
                }
                else{
                    L = mid + 1;
                }
            }
            return false;
        }
    };

int main() {
    Solution sol;
    int num = 16; // Example input
    bool result = sol.isPerfectSquare(num);
    cout << "Is perfect square: " << (result ? "true" : "false") << endl;

    num = 14; // Another example input
    result = sol.isPerfectSquare(num);
    cout << "Is perfect square: " << (result ? "true" : "false") << endl;
    return 0;
}