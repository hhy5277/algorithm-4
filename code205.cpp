/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        
        int maxLength = 0;
        
        stk.push(-1);
        
        for(int i = 0; i < s.size(); ++i){
            int t = stk.top();
            
            if(t!=-1 && s[i] == ')' && s[t] == '('){
                stk.pop();
                maxLength = max(maxLength, i - stk.top());
            }else{
                stk.push(i);
            }
        }
        
        return maxLength;
    }
};