class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size() - 1;
        while(L != R){
            if(numbers[L] + numbers[R] == target) break;
            else if(numbers[L] + numbers[R] < target) L++;
            else if(numbers[L] + numbers[R] > target) R--;
        }
        return {L+1, R+1};
    }
};
