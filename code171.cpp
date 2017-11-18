/*
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/
/*
思路：
先把数组里面的所有的数字进行异或，得到一个数字。
然后，找出这个数字的其中某位为1的在第几位。以这个作为区分，分成两个数组。
分别对这两个数组进行异或，各得到一个数字。而得到的这两个数字，就是我们要找的那两个数字。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int n = data.size();

        int res = 0;
        for (int i = 0; i < n; ++i) {
            res ^= data[i];
        }

        int mask = 1;
        while (0 == (mask & res)) { // 找出num1和num2二进制中，第一位不同的那个mask
            mask = mask << 1;
        }

        // 开始划分数组
        vector<int> v1, v2;
        for (int i = 0; i < n; ++i) {
        	if (0 == (mask & data[i])) {
        		v1.push_back(data[i]);
        	}
        	else {
        		v2.push_back(data[i]);
        	}
        }


        *num1 = 0;
        int n1 = v1.size();
        for (int i = 0; i < n1; ++i) { // 开始找出num1
        	*num1 ^= v1[i];
        }

        *num2 = 0;
        int n2 = v2.size();
        for (int i = 0; i < n2; ++i) { // 开始找出num2
        	*num2 ^= v2[i];
        }
    }
};