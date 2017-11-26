/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
*/
/*
思路：
使用计数排序。  --时间复杂度O(n)，空间复杂度O(1)。
分别记录0、1、2的个数，然后再依据它们的个数，进行存放。
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (0 == n) {
        	return ;
        }

        // 计数
        int x = 0;
        int y = 0;
        int z = 0;

        for (int i = 0; i < n; ++i) {
        	if (0 == nums[i]) {
        		++x;
        	}
        	else if (1 == nums[i]) {
        		++y;
        	}
        	else {
        		++z;
        	}
        }

        // 排序
        for (int i = 0; i < n; ++i) {
        	if (i < x) {
        		nums[i] = 0;
        	}
        	else if (i >= x && i < x + y) {
        		nums[i] = 1;
        	}
        	else {
        		nums[i] = 2;
        	}
        }
    }
};