/*
题目描述
在一个字符串(1<=字符串长度<=10000，
全部由字母组成)中找到第一个只出现一次的字符,
并返回它的位置
*/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        int n = str.size();
        map<char, int> m;

        for (int i = 0; i < n; ++i) {
            ++m[str[i]];
        }

        for (int i = 0; i < n; ++i) {
        	if (m[str[i]] == 1) {
        		return i;
        	}
        }

        return -1;
    }
};