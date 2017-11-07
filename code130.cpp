/*
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        int start = 0, end = n - 1;
        int middle = start + (end - start) / 2;

        int index = partition(numbers, start, end);

        while (index != middle) {
        	if (index < middle) {
        		start = index + 1;
        	}
        	if (index > middle) {
        		end = index - 1;
        	}

        	index = partition(numbers, start, end);
        }

        int res = numbers[index];

        if (checkHalf(numbers, res) == true) {
        	return res;
        }
        else {
        	return 0;
        }
    }

    int partition(vector<int>& numbers, int left, int right) {
    	int v = numbers[left];
        int j = left; // 分界线

        for (int i = left + 1; i <= right; ++i) {
        	if (numbers[i] < v) {
        		swap(numbers[j + 1], numbers[i]);
        		++j;
        	}
        }

        swap(numbers[left], numbers[j]);

        return j;
    }

    bool checkHalf(vector<int>& numbers, int target) {
        int n = numbers.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
        	if (target == numbers[i]) {
        		++count;
        		if (count >= ((n + 1) / 2)) {
        			return true;
        		}
        	}
        }

        return false;
    }
};