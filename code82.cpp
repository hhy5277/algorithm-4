/*
Given an array of integers and an integer k, 
find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
题目的意思是存在即可返回true
*/
/*
思路：
利用哈希表来存放每个数字在数组中的位置，
同时每次都要更新数字在数组中的位置。
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::map<int, int> m;

        int n = nums.size();
        std::map<int, int>::iterator iter;

        for (int i = 0; i < n; i++) {
        	if ((iter = m.find(nums[i])) != m.end()) {
                if ((i - iter->second) <= k) {
                	return true;
                }
                else {
                	m.erase(iter);
                }
        	}

        	m[nums[i]] = i;
        }

        return false;
    }
};