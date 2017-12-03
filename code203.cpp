#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{
	int cow_nums;
	cin >> cow_nums;
	int x[cow_nums];
	for (int i = 0; i < cow_nums; ++i) {
		cin >> x[i];
	}

	sort(x, x + cow_nums);

	long long res = 1;

	for (int i = 0; i < cow_nums; ++i) {
		res *= (x[i] - i);
		res %= 1000000007;
	}

	cout << res;
}