class Solution {
public:
    string addBinary(string a, string b) {
        string r;
        int i = a.size() - 1, j = b.size() - 1, c = 0;
        while (i >= 0 || j >= 0 || c) {
            if (i >= 0) c += a[i--] - '0';
            if (j >= 0) c += b[j--] - '0';
            r.push_back(char('0' + (c & 1)));
            c >>= 1;
        }
        reverse(r.begin(), r.end());
        return r;
    }
};
