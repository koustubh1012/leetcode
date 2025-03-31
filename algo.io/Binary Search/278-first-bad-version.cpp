#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

using namespace std;

bool isBadVersion(int version) {
    // This is a mock implementation for demonstration purposes.
    // In a real scenario, this function would be provided by the system.
    return version >= 4; // Let's say versions 4 and above are bad
}

class Solution {
    public:
        int firstBadVersion(int n) {
            int L = 0;
            int R = n;
            int mid;
            while(L <= R){
                mid = L + (R - L)/2;
                if (isBadVersion(mid) && !isBadVersion(mid-1)){
                    return mid;
                }
                else if (!isBadVersion(mid)){
                    L = mid + 1;
                }
                else {
                    R = mid - 1;
                }
            }
            return mid;
        }
    };

int main() {
    Solution sol;
    int n = 5; // Example input
    int result = sol.firstBadVersion(n);
    cout << "First bad version: " << result << endl;
    return 0;
}