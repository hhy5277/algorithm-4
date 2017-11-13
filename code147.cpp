/*
题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。
*/
/*
其实，找到的第一组数据就是乘积最小的了，所以没有必要继续往后面找了。（我的代码有一些多余）
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    	int n = array.size();
    	vector<int> v;

        int front = 0, end = n - 1;
    	int min_product = INT_MAX;

        while (front < end) {
        	if ((array[front] + array[end] == sum) && (array[front] * array[end] < min_product)) {
        		v.clear();
        		v.push_back(array[front]);
        		v.push_back(array[end]);

        		min_product = array[front] * array[end];

        		++front;
        		--end;
        	}
        	else if (array[front] + array[end] < sum) {
        		++front;
        	}
        	else {
        		--end;
        	}
        }

        return v;
    }
};