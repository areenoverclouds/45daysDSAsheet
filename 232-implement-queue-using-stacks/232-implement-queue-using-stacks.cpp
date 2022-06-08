class MyQueue {
public:
    stack<int> st1, st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int ret;
        while(st1.size() > 1){
            st2.push(st1.top());
            st1.pop();
        }
        ret = st1.top();
        st1.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ret;
    }
    
    int peek() {
        int ret;
        while(st1.size() > 1){
            st2.push(st1.top());
            st1.pop();
        }
        ret = st1.top();
        st2.push(st1.top());
        st1.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return ret;
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()) return true;
        return false;
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