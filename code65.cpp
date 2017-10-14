/*
思路：
用两个栈来模拟：
第一个栈s1用来保存队列中数据的真实顺序。
第二个栈s2用来暂时存放数据，每次操作完最终都是保持空的状态。
*/
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s1; // 保存队列中数据的真实顺序
    stack<int> s2; // 用来暂时存放数据，最终要保持空的状态

    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!s1.empty()) {
            int data = s1.top();
            s1.pop();

            return data;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (!s1.empty()) {
            return s1.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if (s1.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */