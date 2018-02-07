#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	string s1;
	while (cin >> s1) { // 这样子就可以输入多组数据了
		int n = s1.size();
		vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
		string s2(s1);
		reverse(s2.begin(), s2.end());

        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < n; ++j) {
        		if (s1[i] == s2[j]) {
        			dp[i + 1][j + 1] = dp[i][j] + 1;
        		}
        		else {
        			dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        		}
        	}
        }

		cout << n - dp[n][n] << endl;
	}

	return 0;
}