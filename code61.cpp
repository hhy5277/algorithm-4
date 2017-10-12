/*
首先不可能从0开始慢慢遍历，这样肯定会超时，
所以可以使用二分查找，那么最多只要logn次即可。
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        long left = 0, right = num;

        while (left <= right) {
        	long mid = left + (right - left) / 2;

        	if ((mid * mid) == num) {
        		return true;
        	}
        	else if ((mid * mid) < num) {
        		left = mid + 1;
        	}
        	else {
        		right = mid - 1;
        	}
        }

        return false;
    }
};