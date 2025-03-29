#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for (int i=0; i<jewels.length(); i++){
            for (int j=0; j<stones.length(); j++){
                if (jewels[i] == stones[j]){
                    count++;
                }
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