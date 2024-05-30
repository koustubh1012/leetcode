class Solution {
public:
    bool isPalindrome(string s) {
        char* ptr1 = &s[0];
        char* ptr2 = &s[s.length()-1];
        while(ptr1<=ptr2){
            if(!((65<=*ptr1 && *ptr1<=90) || (97<=*ptr1 && *ptr1<=122) || ('0'<=*ptr1 && *ptr1<='9'))){
                ptr1++;
                continue;
            }
            if(!((65<=*ptr2 && *ptr2<=90) || (97<=*ptr2 && *ptr2<=122) || ('0'<=*ptr2 && *ptr2<='9'))){
                ptr2--;
                continue;
            }
            if(tolower(*ptr1)!=tolower(*ptr2)){
                return false;
            }
            ptr1++;
            ptr2--;
        }
        return true;
    }
};
