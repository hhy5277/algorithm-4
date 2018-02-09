/*
Given a string S and a string T, count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/
class Solution {
public:
	/*用删除的方法将串s变换到t，计算变换方法数*/
	int numDistinct(string s, string t) {
		if (s.empty() || t.empty())
			return 0;
		else if (s.length() < t.length())
			return 0;
		else
		{
			//动态规划
			int ls = s.length(), lt = t.length();
			/*保存由字符串s(0,i) --> t(0,j)的方法数*/
			vector<vector<int> > dp(ls + 1, vector<int>(lt + 1, 0));
			dp[0][0] = 1;
			for (int i = 0; i < ls; ++i)
			{
				/*s(0,i) 转换为 t(0)的方法数为1*/
				dp[i][0] = 1;
			}//for
			for (int i = 1; i <= ls; ++i)
			{
				for (int j = 1; j <= lt && j <= i; ++j)
				{
					/*首先不管当前字符是否相同，为dp[i][j]赋初值*/
					dp[i][j] = dp[i - 1][j];
					if (s[i-1] == t[j-1])
					{
						/*如果s和t的当前字符相同，有两种选择保留或不保留*/
						dp[i][j] += dp[i - 1][j - 1];
					}//if
				}//for
			}//for
			return dp[ls][lt];
		}
	}	
};