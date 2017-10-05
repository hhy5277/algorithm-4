/*
思路：
任何一个3的x次方一定能被int型里最大的3的x次方整除
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 ? !(1162261467 % n) : 0;
    }
};