/*
Given an array of integers and an integer k, 
you need to find the number of unique k-diff pairs in the array. 
Here a k-diff pair is defined as an integer pair (i, j), 
where i and j are both numbers in the array and their absolute difference is k.

Example 1:
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
Example 2:
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
Example 3:
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
*/
/*
思路：
如果发现做减法会加大解题难度的话，那么就可以逆向思维，做加法。
我们使用哈希表把每个数字出现的次数保存起来。
遍历这个哈希表，让键加上k得到一个值，如果得到的这个值也在哈希表的键中，那么可以凑成一组(i, j)
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int res = 0;

        for (int num : nums) {
        	++um[num];
        }

        for (auto item : um) {
        	if ((k == 0) && (item.second > 1)) {
        		++res;
        	}
        	if ((k > 0) && (um.count(item.first + k))) {
        		++res;
        	}
        }

        return res;
    }
};