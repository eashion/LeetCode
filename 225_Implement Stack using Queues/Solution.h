class MyStack {
queue<int> que;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int cnt = que.size()-1;
        int tmp;
        while( cnt-- ){
            tmp = que.front();
            que.pop();
            que.push(tmp);
            
        }
        tmp = que.front();
        que.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        int cnt = que.size()-1;
        int tmp;
        while( cnt-- ){
            tmp = que.front();
            que.pop();
            que.push(tmp);
            
        }
        tmp = que.front();
        que.pop();
        que.push(tmp);
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
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
