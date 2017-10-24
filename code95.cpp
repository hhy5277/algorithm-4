/*
Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, 
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/
/*
思路：
把整个大数组排序之后，和原来的nums相比较，
直到发现不同的元素之后，记录索引。
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        std::vector<int> v(nums);
        sort(v.begin(), v.end());

        int start = 0;
        int end = nums.size() - 1;

        while ((start <= end) && (v[start] == nums[start])) {
        	start++;
        }
        
        while ((end >= start) && (v[end] == nums[end])) {
        	end--;
        }

        return (end - start + 1);
    }
};