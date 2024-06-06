class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for(short i=0; i<32; i++){
            m = m | ((n>>i) & 1)<<(31-i);
        }        
        return m;
    }
};
