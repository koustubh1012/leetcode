class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // cretae left pointer and set
        unordered_set<char> set;
        int L = 0;
        int max_length = 0;

        // iterate Right point one at a time
        for(int R = 0; R < s.size(); R++){
            // if element in set, move left pointer
            while(set.find(s[R]) != set.end()){
                set.erase(s[L]);
                L++;
            }
            // if element is not seen before, insert in set
            if(set.find(s[R]) == set.end()){
                set.insert(s[R]);
            }
            max_length = max(max_length, R - L + 1);
        }
        return max_length;
    }
};
