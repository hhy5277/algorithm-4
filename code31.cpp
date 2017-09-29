/*
Given an array of integers, 
find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::map<int, int> m;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
        	m[nums[i]] = 0;
        }

        for (int i = 0; i < n; i++) {
        	if (m[nums[i]] == 1){
        		return true;
        	}
        	else {
        		m[nums[i]]++;
        	}
        }

        return false;
    }
};