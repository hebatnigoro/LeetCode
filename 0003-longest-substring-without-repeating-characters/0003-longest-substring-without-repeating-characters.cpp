class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        vector<int> last(256, -1);
        int n = s.size(), start = 0, x = 0;
        for (int i = 0; i < n; ++i) {
            unsigned char c = s[i];
            if (last[c] >= start) start = last[c] + 1;
            last[c] = i;
            x = max(x, i - start + 1);
        }
        return x;
    }
};
