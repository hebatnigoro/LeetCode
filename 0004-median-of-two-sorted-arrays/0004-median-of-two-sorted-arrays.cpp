class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A);
        int m = A.size(), n = B.size();
        int left = (m + n + 1) / 2, lo = 0, hi = m;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = left - i;
            int Aleft  = (i == 0 ? INT_MIN : A[i - 1]);
            int Aright = (i == m ? INT_MAX : A[i]);
            int Bleft  = (j == 0 ? INT_MIN : B[j - 1]);
            int Bright = (j == n ? INT_MAX : B[j]);
            if (Aleft <= Bright && Bleft <= Aright) {
                if ((m + n) & 1) return max(Aleft, Bleft);
                return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
            } else if (Aleft > Bright) hi = i - 1;
            else lo = i + 1;
        }
        return 0.0;
    }
};
