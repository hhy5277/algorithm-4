/*
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    	int n = input.size();
    	std::vector<int> v;

        if (k <= 0 || n < k) {
            return v;
        }

        int start = 0, end = n - 1;

        int index = partition(input, start, end);

        while (index != (k - 1)) {
        	if (index < (k - 1)) {
        		start = index + 1;
        		index = partition(input, start, end);
        	}
        	if (index > (k - 1)) {
        		end = index - 1;
        		index = partition(input, start, end);
        	}
        }

        for (int i = 0; i <= index; ++i) {
        	v.push_back(input[i]);
        }

        return v;
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
};