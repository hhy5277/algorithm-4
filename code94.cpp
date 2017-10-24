/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000).
*/
/*
思路：
关键是如何把二进制中的每一位取下来。
方法1：
可以对2取余。
方法2：
用1去进行位于。
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t b = 0;

        for (size_t i = 0; i < 32; i++){
            b = b << 1;
            b += (n % 2);
            n = n >> 1;
        }

        return b;
    }
};