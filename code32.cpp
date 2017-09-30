/*
Given a string which consists of lowercase or uppercase letters, 
find the length of the longest palindromes that can be built with those letters.

This is case sensitive, 
for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
*/
/*
思路：
计算每个字符出现的次数，
如果是偶数，那么可以形成回文串。
如果是奇数，那么减掉1个字符之后可以形成回文串。
最后判断回文串中字符的个数是否等于原串的字符个数，
如果不等，那么还可以再加入一个字符作为回文串的中间那个字符
*/
class Solution {
public:
    int longestPalindrome(string s) {
        std::map<char, int> m;

        int n = s.size();

        for (int i = 0; i < n; i++) {
        	m[s[i]] = 0;
        }

        for (int i = 0; i < n; i++) {
        	m[s[i]]++;
        }

        int count = 0;

        for (std::map<char, int>::iterator i = m.begin(); i != m.end(); ++i) {
        	if (i->second % 2 == 0) {
        		count += i->second;
        	}
            else {
                count += i->second - 1;
            }
            
        }

        if (count == n) {
            return count;
        }
        else if (count < n) {
        	return count + 1;

        }
    }
};