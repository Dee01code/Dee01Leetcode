class MyQueue {
public:
    
    stack<int> insert, remove;
    
    MyQueue() {
        insert = stack<int>();
        remove = insert;
    }
    
    void push(int x) {
        insert.push(x);
    }
    
    int pop() {
        if(!remove.empty()){
            int toPop = remove.top();
            remove.pop();
            return toPop;
        }
        
        while(!insert.empty()){
            remove.push(insert.top());
            insert.pop();
        }
        
        int toPop = remove.top();
        remove.pop();
        return toPop;
        
    }
    
    int peek() {
        if(!remove.empty()) return remove.top();
        
        while(!insert.empty()){
            remove.push(insert.top());
            insert.pop();
        }
        
        return remove.top();
    }
    
    bool empty() {
        if(insert.empty() && remove.empty()) return 1;
        return 0;
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