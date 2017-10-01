class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
        	return 0;
        }
        if (n == 1) {
        	return 1;
        }

        int count = 1;
        int max_count = 1;

        for (int i = 1; i < n; i++) {
        	if (nums[i] > nums[i - 1]) {
        		count++;
        	}
        	else {
        		count = 1;
        	}
        	max_count = max(count, max_count);
        }

        return max_count;
    }
};