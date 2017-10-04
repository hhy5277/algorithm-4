/*
We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.

Now, given an integer array, 
you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/
/*
思路：
1、排序
2、用哈希表记录每个数字出现的次数
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();

        if (n < 1) {
        	return 0;
        }

        int max_length = 0;
        int temp_length;

        sort(nums.begin(), nums.end());
        
        std::map<int, int> m;

        for (int i = 0; i < n; i++) {
        	m[nums[i]] = 0;
        }

        for (int i = 0; i < n; i++) {
        	m[nums[i]]++;
        }

        for (int i = 0; i < n - 1; i++) {
        	if (nums[i + 1] - nums[i] == 1) {
        		temp_length = m[nums[i + 1]] + m[nums[i]];
        		max_length = max(temp_length, max_length);
        	}
        }
        
        return max_length;
    }
};