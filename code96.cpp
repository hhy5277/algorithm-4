/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack {
private:
	std::vector<int> v;
	int size; // 容器中元素的个数
public:
    /** initialize your data structure here. */
    MinStack() {
        size = 0;
    }
    
    void push(int x) {
        v.push_back(x);
        ++size;
    }
    
    void pop() {
        v.erase(--v.end());
        --size;
    }
    
    int top() {
        return v[size - 1];
    }
    
    int getMin() {
        std::vector<int>::iterator iter;
        int min_num = INT_MAX;

        for (iter = v.begin(); iter != v.end(); iter++) {
            min_num = min(min_num, *iter);
        }

        return min_num;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */