/*
Given two binary strings, 
return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int la = a.length();
        int lb = b.length();

        if (la == 0) { return b; }
        if (lb == 0) { return a; }

        int lmax = max(la, lb);
        int add = '0';

        for (int i = 0; i < lmax; i++) {
            char ca = la > i ? a[la-i-1] : '0';
            char cb = lb > i ? b[lb-i-1] : '0';
            char s = (ca == cb ? '0' : '1');
            char sj = (s == add ? '0' : '1');

            if (ca == '1' && cb == '1'
                    || s == '1' && add == '1') {
                add = '1';        
            }
            else {
                add = '0';
            }

            ret += sj;
        }

        if (add == '1') {
            ret += add;
        }

        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};