/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/
/*
思路：
用只含一个1的二进制数去和目标数字进行位与。
如果位与的结果不为0，说明这个位置上的是1。
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        int temp_1 = 1;

        for (int i = 0; i < 32; i++) {
        	int temp_2 = temp_1<<i;
        	if ((n & temp_2) != 0) {
        		res++;
        	}
        }

        return res;
    }
};