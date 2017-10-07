/*
判断一个数是否是2的幂
*/
/*
思路：
依据2的N次幂的特点：仅有首位为1，其余各位都为0
*/
class Solution {  
public:  
    bool isPowerOfTwo(int n) {  
        return (n>0) && (!(n&(n-1)));  
    }  
};  