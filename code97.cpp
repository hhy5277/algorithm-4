/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/*
思路：
方法一：
使用二分查找法。
class Solution {
public:
    int mySqrt(int x) {
    	if (x == 0) {
    		return 0;
    	}

        long left = 1, right = x; // 不能定义为int类型

        while (left <= right) {
        	long mid = left + (right - left) / 2;

        	if ((mid * mid == x) || ((mid * mid < x) && ((mid + 1) * (mid + 1) > x))) {
        		return mid;
        	}
        	else if ((mid * mid) > x) {
        		right = mid - 1;
        	}
        	else {
        		left = mid + 1;
        	}
        }
    }
};

****************************************
方法二：                                *
牛顿迭代法。                             *
                                       *     
class Solution {                       * 
public:                                *
    int mySqrt(int x) {                * 
        long root = x;                 *
        while (root*root > x) {        * 
            root = (root + x/root) / 2;*
        }                              *
        return root;                   *
    }                                  *
};                                     *
****************************************
*/ 
