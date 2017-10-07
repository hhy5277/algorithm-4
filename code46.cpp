class Solution {
public:
    int climbStairs(int n) {
        if (1 == n) {
        	return 1;
        }
        if (2 == n) {
        	return 2;
        }

        int* temp_ret = new int[n];
        temp_ret[0] = 1;
        temp_ret[1] = 2;

        for (int i = 2; i < n; i++) {
        	temp_ret[i] = temp_ret[i - 1] + temp_ret[i - 2];
        }

        return temp_ret[n - 1];
    }
};