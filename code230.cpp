/*
给出两个字符串（可能包含空格）,找出其中最长的公共连续子串,输出其长度。 
输入描述:
输入为两行字符串（可能包含空格），长度均小于等于50.


输出描述:
输出为一个整数，表示最长公共连续子串的长度。

输入例子1:
abcde
abgde

输出例子1:
2
*/

/*
水题
动态规划
*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s1, s2;
	cin >> s1 >> s2;

	int s1_length = s1.size();
	int s2_length = s2.size();
	int dp[s1_length + 1][s2_length + 1];

    int max_length = 0;

    for (int i = 0; i < s1_length; ++i) {
    	for (int j = 0; j < s2_length; ++j) {
            dp[i][j] = 0;
    	}
    }
    

    for (int i = 0; i < s1_length; ++i) {
    	for (int j = 0; j < s2_length; ++j) {
            if (s1[i] == s2[j]) {
            	if (i > 0 && j > 0) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
            	}
            	else {
            		dp[i][j] = 1; // 说明至少有一个字符是字符串的第一个字符
            	}
            	if (max_length < dp[i][j]) {
            		max_length = dp[i][j];
            	}
            }
    	}
    }

    cout << max_length;
}