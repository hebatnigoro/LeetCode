class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.size(), spaces = 0;
        for (char c : text) if (c == ' ') ++spaces;

        vector<string> w;
        for (int i = 0; i < n; ) {
            if (text[i] == ' ') { ++i; continue; }
            int j = i;
            while (j < n && text[j] != ' ') ++j;
            w.emplace_back(text.substr(i, j - i));
            i = j;
        }

        string res; res.reserve(n);
        if (w.size() == 1) {
            res = w[0];
            res.append(spaces, ' ');
            return res;
        }

        int gap = spaces / (int(w.size()) - 1);
        int tail = spaces % (int(w.size()) - 1);

        for (int i = 0; i < (int)w.size(); ++i) {
            if (i) res.append(gap, ' ');
            res += w[i];
        }
        res.append(tail, ' ');
        return res;
    }
};
