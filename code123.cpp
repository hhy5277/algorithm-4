/*
题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
*/
class Solution {
private:
	stack<int> stk1, stk2;
	int min_value;
public:
    void push(int value) {
    	if (stk1.empty()) {
    		min_value = value;
    		stk1.push(value);
    	    stk2.push(value);
    	}
    	else if (value < min_value) {
    		min_value = value;
    		stk1.push(value);
    		stk2.push(value);
    	}
    	else if (value >= min_value) {
    		stk1.push(value);
    		stk2.push(min_value);
    	}
    }
    void pop() {
    	stk1.pop();
    	stk2.pop();
    	min_value = stk2.top();
    }
    int top() {
    	return stk1.top();
    }
    int min() {
    	return min_value;
    }
};