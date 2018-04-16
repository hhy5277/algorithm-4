/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/*
思路：
向string 中插入( 和 )，每插入一个就减1。 那么如何保证这个combination 是正确的呢？

插入数量不超过n
可以插入 ） 的前提是 ( 的数量大于 ）

其中，( 剩余的个数用right来表示，) 剩余的个数用left来表示。
*/

/*
遇到的问题：
使用push_back来连接字符串过不了，但是直接用+号来连接字符串可以过。
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
        string part = "";

        __generateParenthesis(res, part, n, n);

        return res;
    }

    void __generateParenthesis(vector<string> &res, string part, int left, int right) {
    	if (left == 0 && right == 0) {
    		res.push_back(part);
    		return ;
    	}

    	if (left > 0) {
    		// part.push_back('(');
    		__generateParenthesis(res, part + '(', left - 1, right);
    	}
    	if (right > 0 && left < right) {
    		// part.push_back(')');
    		__generateParenthesis(res, part + ')', left, right - 1);
    	}
    }
};