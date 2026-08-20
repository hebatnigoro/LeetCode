class Solution {
public:
    int reverseBits(int n) {
        uint32_t result = 0;
        uint32_t num = n;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            result |= (num & 1);
            num >>= 1;
        }
        return result;
    }
};