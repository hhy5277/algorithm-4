/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".
*/
/*
思路：
如果两个指针指向的两个字符都是元音，那么交换；
如果其中哪个字符不是元音，那么移动指针
*/
class Solution {
public:
    string reverseVowels(string s) {
        set<char> ss;
        ss.insert('a');
        ss.insert('A');
        ss.insert('e');
        ss.insert('E');
        ss.insert('i');
        ss.insert('I');
        ss.insert('o');
        ss.insert('O');
        ss.insert('u');
        ss.insert('U');

        int n = s.size();

        for (int i = 0, j = n - 1; i < j; ) {
        	if (ss.count(s[i]) && ss.count(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
        	}
        	else {
        		if (!ss.count(s[i])) {
        			i++;
        		}
        		if (!ss.count(s[j])) {
        			j--;
        		}
        	}

        }

        return s;
    }
};