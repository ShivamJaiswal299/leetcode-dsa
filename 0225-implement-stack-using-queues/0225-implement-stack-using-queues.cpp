class MyStack {
public:
    queue<int> q;
    MyStack() {
      //this constructor is not needed here.
    }
    
    void push(int x) {
      q.push(x);
      for(int i=0;i<q.size()-1;i++){
        int val = q.front();
        q.pop();
        q.push(val);
      }
      //now queue is in our desired order 
    }
    
    int pop() {
      int val = q.front();
      q.pop();
      return val;
    }
    
    int top() {
      int val = q.front();
      return val;
    }
    
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