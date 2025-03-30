#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        int numJewelsInStones(string jewels, string stones) {
            int count = 0;
            unordered_set<char> jewel_set(jewels.begin(), jewels.end());
            for (char stone : stones) {
                if (jewel_set.count(stone)) { // Check if stone is a jewel
                    count++;
                }
            }
            return count;
        }
    };

int main() {
    Solution sol;
    string jewels = "aA";
    string stones = "aAAbbbb";
    int result = sol.numJewelsInStones(jewels, stones);
    cout << "The number of jewels in stones is: " << result << endl;
    return 0;
}
// Output: The number of jewels in stones is: 3