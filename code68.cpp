/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/
/*
思路：
使用等差数列求和公式来倒过来退出层数。
*/
class Solution {
public:
    int arrangeCoins(int n) {
    	unsigned int m = n;
    	int temp = sqrt(2 * m + 0.25) - 0.5;
    	return temp;
    }
};