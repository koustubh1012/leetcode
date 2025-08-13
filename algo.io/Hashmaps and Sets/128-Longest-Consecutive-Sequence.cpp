class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        //handle edge case of 0 length
        if (nums.size() == 0){
            return 0;
        }

        // create an unordered set
        unordered_set<int> set;
        for(int n:nums){
            set.insert(n);
        }

        // initialise max length
        int max_length = 1;
    
        // check the sequence
        for(int n : set){
            // only check sequence if n - 1 does not exist 
            if (set.find(n - 1) == set.end()){
                int next_num = n + 1;
                // find the next number until not found
                while(set.find(next_num) != set.end()){
                    next_num++;
                }
                int length = next_num - n;
                // check if new length is max length
                if(length > max_length){
                    max_length = length;
                }
            }
        }
        return max_length;
    }
};
