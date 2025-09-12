class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= (int)s.size()) return s;
        string res; res.reserve(s.size());
        int cycle = 2 * numRows - 2;
        for (int r = 0; r < numRows; ++r) {
            for (int j = r; j < (int)s.size(); j += cycle) {
                res.push_back(s[j]);
                int k = j + cycle - 2 * r;
                if (r && r != numRows - 1 && k < (int)s.size()) res.push_back(s[k]);
            }
        }
        return res;
    }
};
