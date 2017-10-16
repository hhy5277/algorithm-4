/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
/*
思路：
使用栈可以解决匹配问题。
检查栈顶元素是否和字符串中的那个字符匹配，如果匹配，则把栈顶元素弹出；
否则把字符压入栈中
如果最后栈里面没有元素，说明字符串匹配成功；否则，失败
*/
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        if ((n % 2) == 1) {
        	return false;
        }

        stack<char> stk;

        for (int i = 0; i < n; i++) {
        	if (!stk.empty()) {
                if ((stk.top() == '(' && s[i] == ')') || (stk.top() == '[' && s[i] == ']') || (stk.top() == '{' && s[i] == '}')) {
                	stk.pop();
                }
                else {
                	stk.push(s[i]);
                }
        	}
        	else {
        		stk.push(s[i]);
        	}

        }

        if (stk.empty()) {
        	return true;
        }
        else {
        	return false;
        }
    }
};