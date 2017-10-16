/*
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
*/
/*
思路：
首先不可能从[1, num)完全遍历一遍，会超时。
所以需要减少一些不必要的判断，如果：
(num % i) == 0，则说明i是num的一个除数；相应的，num / i 也是num的一个除数。
因此，这样可以减少许多不必要的遍历。
至于遍历到哪里，我们选取sqrt(num)
*/
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (1 == num) {
        	return false;
        }

        int n = sqrt(num);
        int sum = 1; // 因为sum不能够加上num自身，所以sum初始化为1

        for (int i = 2; i <= n; i++) {
        	if ((num % i) == 0) {
                sum += i;
                sum += (num / i);
        	}
        }

        return (sum == num);
    }
};