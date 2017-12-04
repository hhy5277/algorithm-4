/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/
/*
思路：
使用二分查找法，
先找到一个target，然后分别向左和向右搜索target的边缘
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v;

    	v.push_back(-1);
    	v.push_back(-1);
        
        int left = 0, right = n - 1;
        while (left <= right) {
        	int mid = left + (right - left) / 2;
        	if (nums[mid] == target) {
                theRes(nums, v, mid, target);

                return v;
        	}
        	else if (nums[mid] < target) {
        		left = mid + 1;
        	}
        	else {
        		right = mid - 1;
        	}
        }

        return v;
    }

    void theRes(vector<int>& nums, vector<int>& v, int index, int target) {
    	// 向左遍历
    	int left = index;
    	for (int i = index - 1; i >= 0; --i) {
            if (nums[i] == target) {
            	left = i;
            }
            else {
            	break;
            }
    	}

    	v[0] = left;
        
        int right = index;
    	for (int i = index + 1; i < nums.size(); ++i) {
            if (nums[i] == target) {
            	right = i;
            }
            else {
            	break;
            }
    	}

    	v[1] = right;
    }
};