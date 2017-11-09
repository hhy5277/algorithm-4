/*
要考虑负数
*/
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	char table[] = "0123456789ABCDEF";
	int m, n; // m是十进制的，n是基数
	cin >> m >> n;

	bool is_less_0 = false;

	if (m < 0) {
		is_less_0 = true;
		m = abs(m);
	}

	stack<char> s;

	while (m > 0) {
		int remain = m % n;
		s.push(table[remain]);
        m /= n;
	}

	if (is_less_0) {
		cout << '-';
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
    
	return 0;
}