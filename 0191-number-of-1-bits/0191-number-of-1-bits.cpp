class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        uint32_t num = n;
        while (num) {
            num &= (num - 1);
            count++;
        }
        return count;
    }
};