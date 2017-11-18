/*
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法。
*/
/*
假设，跳到n级台阶有f(n)种跳法，那么，
如果第一次跳了1个台阶，则剩下的n - 1个台阶有f(n - 1)种跳法；
如果第一次跳了2个台阶，则剩下的n - 2个台阶有f(n - 2)种跳法
*/
class Solution {
public:
    int jumpFloor(int number) {
        int res[number + 1]; // 表示跳上i级台阶有res[i]种跳法
        res[0] = 0;
        res[1] = 1;
        res[2] = 2;

        for (int i = 3; i <= number; ++i) {
        	res[i] = res[i - 1] + res[i - 2];
        }

        return res[number];
    }
};