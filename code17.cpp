/*
Given a column title as appear in an Excel sheet,
return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        std::map<char, int> m;

        for (char c = 'A', i = 1; c <= 'Z'; c++, i++) {
        	m[c] = i;
        }

        int n = s.size() - 1; // n代表字符串的下标
        int sum = 0;
        int base = 1;

        while (n >= 0) {
            sum += m[s[n]] * base;
            base *= 26; // 逢26进1
            n--;
        }

        return sum;
    }
};