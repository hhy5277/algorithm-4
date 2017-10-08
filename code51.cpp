/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/
/*
思路：
如果sum < 0的话，那么就没有必要拼接后面的数字了，因为后面的一项如果为负数，那么拼接之后会更小；
如果后面的一项是正数，那么与前面的负数串相加会变小。
这里我们需要一个max变量来保存当前的最大值。
因为，当sum为正的时候，加上后面的一项之后，可能会比max要大
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN, sum = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
        	sum += nums[i];

        	if (sum > max) {
        		max = sum;
        	}
            if (sum < 0) {
            	sum = 0;
            }
        }

        return max;
    }
};