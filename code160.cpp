/*
Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
*/
/*
思路：
把所有数字的每一位都累加起来，存放在长度为32的int型数组里面。
然后对每一位对3取模，
最终结果就是那个只出现一次的数字。
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int n = nums.size();
    	int res[32];
    	for (int i = 0; i < 32; ++i) {
    		res[i] = 0;
    	}
        
        // 把每一位都累加起来
    	for (int i = 0; i < n; ++i) {
    		int test = 1;

    		for (int j = 31; j >= 0; --j) {
    			if ((nums[i] & test) != 0) {
    				++res[j];
    			}

    			test = test << 1;
    		}
    	}

    	// 数组中的每一位对3取模
    	for (int i = 0; i < 32; ++i) {
    		res[i] %= 3;
    	}

    	// 对剩下的那个数，二进制转十进制
    	int num = 0;
    	for (int i = 31; i >= 0; --i) {
    		num += (res[i] << (31 - i));
    	}

    	return num;
    }
};