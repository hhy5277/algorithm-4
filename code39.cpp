/*
Given two non-negative integers num1 and num2 represented as string, 
return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
/*
该算法为大数相加使用字符串string实现的问题。
首先算出两个字符串的长度，
并从两个字符串的最后一个字符开始循环，
两个字符串对应位置的值相加，若有进制，则保存。
若某一字符串的长度较长，需要将该字符串剩下的字符遍历完成，
所以循环退出的条件是i>=0||j>=0；
这里需要注意的是对字符串位置的操作，
需要从两个给定字符串的最后一个位置开始，
并且每次得到的结果应放置到结果字符串的首位置。
对于数字和字符的相互转换，这里需要用到‘0’
*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1_length = num1.size();
        int num2_length = num2.size();
        int i = num1_length - 1, j = num2_length - 1;
        string s = "";
        int carry = 0;

        while (i >= 0 || j >= 0) {
        	int temp = 0;

            if (i >= 0) {
            	temp += num1[i] - '0';
            }
            if (j >= 0) {
            	temp += num2[j] - '0';
            }

            if (carry == 1) {
            	temp++;
            }

            carry = temp / 10;
            temp = temp % 10;

            s = char(temp + '0') + s;

            i--;
            j--;
        }

        if (carry == 1) {
            s  = char(carry + '0') + s;
        }

        return s;
    }
};