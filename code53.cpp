/*
Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note that 1 is typically treated as an ugly number.
*/
/*
思路：
判断一个数被2、3、5循环的除之后是否为1，若是1，则为真。
*/
class Solution {
public:
    bool isUgly(int num) {
    	if (0 == num) {
    		return false;
    	}
        if (1 == num) {
        	return true;
        }

        while (num % 2 == 0) {
        	num /= 2;
        }

        while (num % 3 == 0) {
        	num /= 3;
        }

        while (num % 5 == 0) {
        	num /= 5;
        }

        if (1 == num) {
        	return true;
        }
        else {
        	return false;
        }
    }
};