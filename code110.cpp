/*
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. 
Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, 
and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, 
and you need convert it to the form of 0+-2i.
*/
/*
思路：
因为(a + bi) * (c + di)  = (ac - bd) + (ad + bc)i;
所以，只需要分解出a, b, c, d即可
*/
class Solution {  
    void getAB(const string& s, int& a, int& b) {  
        int i;

        for(i = 0; i < s.size(); ++i) {
            if(s[i] == '+') {
                a = stoi(s.substr(0, i));
                break;
            }  
        }  

        b = stoi(s.substr(i + 1, s.size() - i - 2));  
    }  
public:  
    string complexNumberMultiply(string a, string b) {
        int aa, ab, ba, bb;
        getAB(a, aa, ab);
        getAB(b, ba, bb);
        return to_string(aa * ba - ab * bb) + "+" + to_string(ab * ba + aa * bb) + "i";
    }
}; 