/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    	int n = tokens.size();
        
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
        	if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int second = stk.top();
                stk.pop();
                int first = stk.top();
                stk.pop();
                int res = calculate(first, second, tokens[i]);
                stk.push(res); // 把计算结果压栈
        	}
        	else {
        		stk.push(stoi(tokens[i]));
        	}
        }

        return stk.top();
    }

    int calculate(int& first, int& second, string& opera) {
    	if (opera == "+") {
    		return first + second;
    	}
        if (opera == "-") {
        	return first - second;
        }
        if (opera == "*") {
        	return first * second;
        }
        if (opera == "/") {
        	return first /second;
        }
    }
};