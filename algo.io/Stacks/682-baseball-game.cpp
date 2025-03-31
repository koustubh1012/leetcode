#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
    public:
        int calPoints(vector<string>& operations) {
            int points = 0;
            vector<int> records;
            for (auto op : operations){
                if (op == "+"){
                    records.push_back(records.end()[-1] + records.end()[-2]);
                }
                else if (op == "D"){
                    records.push_back(2*records.back());
                }
                else if (op == "C"){
                    records.pop_back();
                }
                else{
                    records.push_back(stoi(op));
                }
            }
            for (auto point : records){
                points += point;

            }
            return points;
        }
    };

int main() {
    Solution sol;
    vector<string> operations = {"5","2","C","D","+"};
    int result = sol.calPoints(operations);
    cout << "\nTotal points: " << result << endl;
    return 0;
}