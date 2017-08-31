/*
《拼数问题》

题目描述

设有n个正整数（n≤20），将它们联接成一排，组成一个最大的多位整数。

例如：n=3时，3个整数13，312，343联接成的最大整数为：34331213

又如：n=4时，4个整数7，13，4，246联接成的最大整数为：7424613

输入输出格式

输入格式：
第一行，一个正整数n。

第二行，n个正整数。

输出格式：
一个正整数，表示最大的整数
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a[25];

/* 
因为是对拼接后生成的字符串进行排序，所以，是比较 x + y 和 y + x
而不是比较 x 和 y
*/
bool cmp(const string x, const string y)
{
	return (x + y) > (y + x);

}

int main(int argc, char const *argv[])
{
	
	int n, i;
	cin>>n; /*输入要拼接的整数的个数*/
	for (i = 0; i < n; i++) {
		cin>>a[i];
	}
	sort(a, a + n, cmp);
	for (i = 0; i < n; i++) {
		cout<<a[i];
	}
	return 0;
}