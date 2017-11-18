/*
题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/
/*
思路：
先对整个字符串进行翻转，然后再局部对单词进行翻转。以空格为间隔，视为一个新的单词（即句号属于一个单词的部分）
*/
class Solution {
public:
    string ReverseSentence(string str) {
    	int n = str.size();
        reverseStr(str, 0, n - 1); // 反转整个字符串

        int left = 0, right = 1;
        while (right <= n) {
        	if (' ' == str[right] || '\0' == str[right]) {
        		reverseStr(str, left, right - 1);
        		left = right + 1;
                right += 2;
        	}
            else {
            	++right;
            }
        }

        return str;
    }

    void reverseStr(string& str, int left, int right) {
    	while (left < right) {
    		swap(str[left], str[right]);
    		++left;
    		--right;
    	}
    }
};