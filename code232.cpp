/*

Description:

Count the number of prime numbers less than a non-negative number, n.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

/*
思路：
使用动态规划
dp[n] 的意思是小于n的质数个数
dp[n] = dp[n - 1] + if (n 是否是质数)
*/

int dp[10000000];

class Solution {
public:
    int countPrimes(int n) {
    	if (0 == n) {
    		return 0;
    	}

    	dp[0] = 0;
    	dp[1] = 0;
    	dp[2] = 1;

        for (int i = 3; i < n; ++i) {
            dp[i] = dp[i - 1];
            if (isPrime(i)) {
            	++dp[i];
            }
        }

        return dp[n - 1];
    }

    bool isPrime(int n) {
    	for (int i = 2; i <= sqrt(n); ++i) {
    		if (n % i == 0) {
    			return false;
    		}
    	}

    	return true;
    }
};