/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
*/
/*
思路：用哈希表存放S字符串中每个字符出现的次数，
然后再根据J字符串中的每个字符来统计出总数
*/
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> m;
        int res = 0;

        int S_length = S.size();

        for (int i = 0; i < S_length; ++i) {
        	++m[S[i]];
        }

        int J_length = J.size();

        for (int i = 0; i < J_length; ++i) {
            if (m.count(J[i])) {
            	res += m[J[i]];
            }
        }

        return res;
    }
};