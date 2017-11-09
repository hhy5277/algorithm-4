/*
一个数组有 N 个元素，求连续子数组的最大和。 例如：[-1,2,1]，和最大的连续子数组为[2,1]，其和为 3 
输入描述:
输入为两行。 第一行一个整数n(1 <= n <= 100000)，表示一共有n个元素 第二行为n个数，即每个元素,每个整数都在32位int范围内。以空格分隔。
*/
#include <iostream>
#include <limits.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;
	cin >> n;

    int nums[n];
    for (int i = 0; i < n; ++i) {
    	cin >> nums[i];
    }

    int max_sum = INT_MIN;
    int max_sum1 = INT_MIN;
    int temp_sum = 0;

    bool is_have_0 = false;

    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
        	is_have_0 = true;
        }

    	temp_sum += nums[i];

    	if (temp_sum < 0) {
    		temp_sum = 0;
    	}
    	if (temp_sum > max_sum) {
    		max_sum = temp_sum;
    	}
    }

    if (max_sum > 0) {
    	cout << max_sum << endl;

    	return 0;
    }

    if (temp_sum == 0 && is_have_0 == false) {
	    for (int i = 0; i < n; ++i) {
	    	temp_sum += nums[i];

	    	if (temp_sum > max_sum1) {
	    		max_sum1 = temp_sum;
	    	}
	    }

	    cout << max_sum1 << endl;

	    return 0;
    }

    if (temp_sum == 0 && is_have_0 == true) {
    	cout << 0 << endl;

    	return 0;
    }

}