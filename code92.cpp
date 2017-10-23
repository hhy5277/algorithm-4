/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. 
Your function should return 0 when the reversed integer overflows.
*/
class Solution {
public:
    int reverse(int x) {
    	bool is_positive;
    	int num = abs(x);
    	long long res = 0; // 为了防止溢出，所以这个保存结果的变量需要开大一些

    	if (x >= 0) {
    		is_positive = true;
    	}
    	else {
            is_positive = false;
    	}

        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }

        if (res > INT_MAX) {
        	return 0;
        }

        if (is_positive) {
        	return res;
        }
        else {
        	return -res;
        }
    }
};