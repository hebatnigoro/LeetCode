class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int m = strs[0].size();
        for (int i = 1; i < (int)strs.size(); ++i) {
            int sz = strs[i].size();
            if (sz < m) m = sz;
        }
        int j = 0;
        for (; j < m; ++j) {
            char c = strs[0][j];
            for (int i = 1; i < (int)strs.size(); ++i)
                if (strs[i][j] != c) return strs[0].substr(0, j);
        }
        return strs[0].substr(0, j);
    }
};