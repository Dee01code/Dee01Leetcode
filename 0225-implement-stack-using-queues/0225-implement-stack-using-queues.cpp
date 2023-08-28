class MyStack {
public:
    
    queue<int> q1;
    queue<int> q2;
    int peek;
        
    MyStack() {
        peek = -1;
    }
    
    void push(int x) {
        q1.push(x);
        peek = x;
    }
    
    int pop() {
        if(q1.empty()) return -1;
        
        while(q1.size() != 1){
            q2.push(q1.front());
            if(q1.size() == 2) peek = q1.front();
            q1.pop();
        }
        
        int ans = q1.front();
        q1.pop();
        q1.swap(q2);
        return ans;
        
    }
    
    int top() {
        return peek;
    }
    
    bool empty() {
        return q1.empty();
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