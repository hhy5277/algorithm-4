/*
题目描述
把只包含因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含因子7。 
习惯上我们把1当做是第一个丑数。
求按从小到大的顺序的第N个丑数。
*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) {
        	return 0;
        }

        int* ugly_numbers = new int[index];
        ugly_numbers[0] = 1;
        int next_index = 1;

        int* multiply2 = ugly_numbers;
        int* multiply3 = ugly_numbers;
        int* multiply5 = ugly_numbers;

        while (next_index < index) {
        	ugly_numbers[next_index] = Min(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);

            if (*multiply2 * 2 <= ugly_numbers[next_index]) {
            	++multiply2;
            }	
            if (*multiply3 * 3 <= ugly_numbers[next_index]) {
            	++multiply3;
            }
            if (*multiply5 * 5 <= ugly_numbers[next_index]) {
            	++multiply5;
            }

            ++next_index;
        }

        int res = ugly_numbers[index - 1];

        delete[] ugly_numbers;

        return res;
    }

    int Min(int num1, int num2, int num3) {
    	int the_min = min(num1, num2);
    	the_min = min(the_min, num3);

    	return the_min;
    }
};