/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. 
Could you implement it using only constant extra space complexity?
*/
/*
思路：

*/
class Solution {  
public:  
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 1; i <= nums.size(); i++) 
            res =res ^ i ^ nums[i-1];
        
        return res;
    }
};