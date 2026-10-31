class MyQueue {
public:
    stack<int> st1, st2;

    MyQueue() {
        // no constructor needed
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        // refill st2 only when it is empty
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (st2.empty()) return -1;
        int val = st2.top();
        st2.pop();
        return val;
    }

    int peek() {
        // same as pop, but don't remove
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        if (st2.empty()) return -1;
        return st2.top();
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};