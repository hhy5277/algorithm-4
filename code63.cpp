/*
Given an array consisting of n integers, 
find the contiguous subarray of given length k that has the maximum average value. 
And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
*/
/*
由于前后滑动窗之间大部分元素相同，
所以没必要大量重复运动（会超时）。
窗口滑动，只需要将离开窗口的元素减掉，
再将新进入窗口的元素加上即可。

所以，其实就是操作滑动距离为1的滑动窗
这里的滑动窗的模型就是四个数字的和，而滑动的意思就是减去sum和的第一个数字，再加上sum之后的一个数字，即实现了滑动

此处，平均数最大等价于和最大，
所以中途运算是不需要算平均数，只需要在最后结果处除以k。
由于数组中存储的是整数，所以直接拿和除以k得到的数字还是整数，要对求得的和进行强制类型转换。
*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    	int sum = 0, res = 0;
    	int n = nums.size();

    	for (int i = 0; i < k; i++) {
    		sum += nums[i];
    	}

    	res = sum;

    	for (int i = 1; i <= n - k; i++) {
    		sum = sum - nums[i - 1] + nums[i + k - 1];
    		res = max(sum, res);
    	}

    	return (double)res / k;
    }
};