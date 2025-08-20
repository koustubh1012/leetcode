class Solution {
public:
    bool isPalindrome(string s) {
        string new_str;
        for(char c : s){
            if(!isalnum(c)) continue;
            new_str += tolower(c);
        }
        cout<<new_str;
        int L = 0;
        int R = new_str.size() - 1;
        while(L < R){
            if(new_str[L] != new_str[R]) return false;
            L++;
            R--;
        }
        return true;
    }
};
