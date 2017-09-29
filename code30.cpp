/*
思路：

将除数不停地一个一个累加，并记录累加次数，直到大于被除数为止。

但是这种方法超时了。

一个一个累加太慢了，那么我们可以换种思路：

使用 移位 操作——左移一位相当于乘以2，而被除数是可以表示成除数的一个线性组合的形式： 

dividend=divisor∗2n1+divisor∗2n2+...+divisor∗2nx

其中0≤n1≤n2≤...≤nx，故我们所要求的结果就是： 
result=2n1+2n2+...+2nx
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool symbol = true; // 代表两者相除是正数
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
        	symbol = false;
        }
        
        int64_t absDividend = abs((int64_t)dividend);
        int64_t absDivisor = abs((int64_t)divisor);
        int64_t res = 0;

        while (absDivisor <= absDividend) {
        	int64_t tmp = absDivisor;
        	int64_t count = 1;
        	while (tmp<<1 < absDividend) {
        		tmp = tmp<<1;
        		count = count<<1;
        	}
            
            res += count;
            absDividend -= tmp;
        }

        if (symbol && res >= INT_MAX) {
        	return INT_MAX;
        }

        return symbol ? res : -res;
    }
};