class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // declare min and max speed
        int min = 1;
        int max = 0;

        // find the max number of bananas in the pile
        for(int n : piles){
            if(n > max){
                max = n;
            }
        }

        // perform binary search for k
        while(min < max){
            int mid = min + (max - min) / 2;
            int hours = 0;
            for(int n : piles)
            {
                hours += ceil(static_cast<double>(n) / mid);
            }
            if(hours <= h){
                max = mid;
            }
            else{
                min = mid + 1;
            }
        }

        return min;
    }
};
