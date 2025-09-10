class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, prev = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            int v;
            switch (s[i]) {
                case 'I': v = 1; break;
                case 'V': v = 5; break;
                case 'X': v = 10; break;
                case 'L': v = 50; break;
                case 'C': v = 100; break;
                case 'D': v = 500; break;
                default: v = 1000;
            }
            ans += (v < prev) ? -v : v;
            prev = v;
        }
        return ans;
    }
};
