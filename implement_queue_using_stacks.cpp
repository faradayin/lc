class MyQueue {
private:
    stack<int> q;
    stack<int> s;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s.empty())
        {
            while(!q.empty())
            {
                s.push(q.top());
                q.pop();
            }

        }
        int val = s.top();
        s.pop();
        return val; 
    }
    
    /** Get the front element. */
    int peek() {
        if(s.empty())
        {
            while(!q.empty())
            {
                s.push(q.top());
                q.pop();
            }
        }
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty()&&q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */