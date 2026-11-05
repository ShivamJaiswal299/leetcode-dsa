class MinStack {
public:
    stack <int> stk;
    stack <int> minstk;
    MinStack() {
    }
    
    void push(int value) {
      if(minstk.empty() || value<=minstk.top()) minstk.push(value);
      stk.push(value);
    }
    
    void pop() {
      if(stk.top()==minstk.top()) minstk.pop();
      stk.pop();  
    }
    
    int top() {
      return stk.top();  
        
    }
    
    int getMin() {
        return minstk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */