class Solution {
public:
    string intToRoman(int num) {
        static const int val[13] = {
            1000,900,500,400,100,90,50,40,10,9,5,4,1
        };
        static const string sym[13] = {
            "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"
        };
        string res; res.reserve(15);
        for (int i = 0; i < 13; ++i)
            while (num >= val[i]) { num -= val[i]; res += sym[i]; }
        return res;
    }
};
