class Solution {
public:
    int hammingWeight(int n) {
        int x;
        int set_bits = 0;
        do{
            x = n % 2;
            if(x==1){
                set_bits+=1;
            }
            n = n / 2;
        }while(n!=0);
        return set_bits;
    }
};
