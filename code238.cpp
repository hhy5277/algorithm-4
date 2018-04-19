/*
Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
*/

/*
思路：
使用两个队列q1、q2。
入栈的话，直接把元素放入队列q2；

出栈的话，先把q2里面的所有元素转移到q1（但是q2最后一个元素不要放入q1里面，因为它是需要被出栈的）
然后再把q1里面的元素全部转移到q2；
*/

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        (this->q2).push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = q2.size();
        for (int i = 0; i < len - 1; ++i) {
            (this->q1).push((this->q2).front());
            (this->q2).pop();
        }

        int res = (this->q2).front();
        (this->q2).pop();

        for (int i = 0; i < len - 1; ++i) {
            (this->q2).push((this->q1).front());
            (this->q1).pop();
        }

        return res;
    }
    
    /** Get the top element. */
    int top() {
        return (this->q2).back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if ((this->q2).empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */