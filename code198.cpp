/*
Implement pow(x, n).


Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/
class Solution {
public:
    // first approach
    double pow(double x, int n) 
    {
        if (!n) return 1;
        long long nLong = n;
        if (nLong < 0)
        {
            x = 1 / x;
            nLong = -nLong;
        }
        
        double res = 1;
        while (nLong)
        {
            if (nLong & 1) res *= x;
            x *= x;
            nLong >>= 1;
        }
        
        return res;
    }
};