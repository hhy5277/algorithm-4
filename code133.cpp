/*
题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
则打印出这三个数字能排成的最小数字为321323。
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
    	int n = numbers.size();
    	sort(numbers.begin(), numbers.end(), compare);
        
        string res = "";

        for (vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter) {
        	res += to_string(*iter);
        }

        return res;
    }

    static bool compare (const int& num1, const int& num2) {
    	string s1 = "", s2 = "";

    	s1 += to_string(num1);
    	s1 += to_string(num2);

    	s2 += to_string(num2);
    	s2 += to_string(num1);

    	return s1 < s2;
    }
};