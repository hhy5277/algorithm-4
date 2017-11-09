#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, sum;
	cin >> n >> sum;

	int a[n];

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	sort(a);

	int count = 0;
	int temp_sum = 0;

	for (int i = n - 1; i >= 1; --i) {
		temp_sum += a[i];
		
		for (int j = i - 1; j >= 0; --j) {
			temp_sum += a[j];

			if (temp_sum == sum) {
				++count;
			}

			if (temp_sum > sum) {
				temp_sum -= a[j];
			}
			
		}


	}



	return 0;
}