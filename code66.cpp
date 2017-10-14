/*
思路：
因为不需要反转单词，所以，只需要通过空格来判断即可
如果当前字符不是空格,而前一个是空格,则段数加1
*/
class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
        	if ((i == 0) && (s[i] != ' ')) {
        		count++;
        	}
        	if ((i > 0) && (s[i] != ' ') && (s[i - 1] == ' ')) {
        		count++;
        	}
        }

        return count;
    }
};