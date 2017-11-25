/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
/*
思路：
先使用二分查找找到最小的那个值（也就是两个递增数组的分界线），
然后判断target落在了哪个递增的区间，
然后对这个区间使用二分查找来找到target。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if (nums.empty()) {
    		return -1;
    	}

        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right) {
        	int mid = left + (right - left) / 2;
        	if (nums[mid] > nums[0]) {
        		left = mid;
        	}
        	if (nums[mid] < nums[n - 1]) {
        		right = mid;
        	}
        	if (1 == right - left) {
        		break;
        	}
        }

        int divide = right;

        if (target >= nums[0] && target <= nums[divide - 1]) {
        	left = 0;
        	right = divide - 1;
        }
        else {
        	left = divide;
        	right = n - 1;
        }

        while (left <= right) {
        	int mid = left + (right - left) / 2;
        	if (nums[mid] > target) {
        		right = mid - 1;
        	}
        	else if (nums[mid] < target) {
        		left = mid + 1;
        	}
        	else {
        		return mid;
        	}
        }

        return -1;
    }
};