/*
思路：
1、二进制形式只有一个1
n & n-1 == 0

2、并且这个1是在奇数位
(n & 0x55555555) == n;
*/
class Solution {
public:
    bool isPowerOfFour(int num) {
    	if (num <= 0) {
    		return false;
    	}

    	return (num & num - 1) == 0 && (num & 0x55555555) == num;
    }
};