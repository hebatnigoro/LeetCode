class Solution {
public:
    bool isValid(string s) {
        string st; st.reserve(s.size());
        for (char c : s) {
            switch (c) {
                case '(': st.push_back(')'); break;
                case '[': st.push_back(']'); break;
                case '{': st.push_back('}'); break;
                default:
                    if (st.empty() || st.back() != c) return false;
                    st.pop_back();
            }
        }
        return st.empty();
    }
};
