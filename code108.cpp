/*
Given an array with n integers, 
your task is to check if it could become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example 1:
Input: [4,2,3]
Output: True
Explanation: You could modify the first 
4
 to 
1
 to get a non-decreasing array.
Example 2:
Input: [4,2,1]
Output: False
Explanation: You can't get a non-decreasing array by modify at most one element.
Note: The n belongs to [1, 10,000].
*/
/*
思路：
当出现了前面大后面小的情况，
可以把前面的变小，或者把后面的变大
*/
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < nums[i - 1]) { // 前面大，后面小
                int temp = nums[i - 1];

                nums[i - 1] = nums[i]; // 把前面的变小
                if(is_sorted(nums.begin(), nums.end()))
                    return true;

                nums[i] = nums[i - 1] = temp; // 或者把后面的变大
                if(is_sorted(nums.begin(), nums.end()))
                    return true;

                return false;
            }
        }

        return true;
    }
};