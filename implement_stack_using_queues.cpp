class MyStack {
private:
//一个队列就可以实现栈了
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int cnt = q.size();
        while(cnt > 1)
        {
            q.push(q.front());
            q.pop();
            cnt--;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */