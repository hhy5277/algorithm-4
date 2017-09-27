/*
Given an array of size n, 
find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
/*
思路：
用哈希表把所有元素出现的次数映射出来
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        std::map<int, int> m;

        for (int i = 0; i < n; i++) {
        	m[nums[i]] = 0;
        }

        for (int i = 0; i < n; i++) {
        	m[nums[i]]++;
        }

        int nums_max_count = m.begin()->second;
        int nums_max = m.begin()->first;

        for (std::map<int, int>::iterator i = m.begin(); i != m.end(); ++i) {
        	if (nums_max_count < i->second) {
        		nums_max_count = i->second;
        		nums_max = i->first;
        	}
        }

        return nums_max;
    }
};