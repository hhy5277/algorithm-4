/*
输入一个正整数n, 求n!(即阶乘)末尾有多少个0？ 比如: n = 10; n! = 3628800,所以答案为2 
输入描述:
输入为一行，n(1 ≤ n ≤ 1000)
*/
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	int res = n / 5;
    int num = res;

    while (num >= 5) {
    	num /= 5;
    	res += num;
    }

    cout << res << endl;

	return 0;
}