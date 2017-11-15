/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> dp(size + 1, false); // d[i] 表示i前面（不包括i那个位置）的字符串是否可以拆分，如果可以，那么就设置为true；否则，设置为false
        dp[0] = true;

        for(int i = 1; i <= size; i++){
            for(int j = 0; j < i; j++){ // 注意，这里j要从0开始遍历。因为，之前满足，在后面如果失败了，那么还是需要重新往前找的。
                if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()){
                    dp[i] = true;
                }
            }
        }
        return dp[size];
    }
};