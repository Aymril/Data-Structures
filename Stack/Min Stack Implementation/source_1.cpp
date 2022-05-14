#include <iostream>
#include <stack>

using namespace std;

class MinStack {
   public:
    long min;
    stack<long> s;
    MinStack() {}

    void push(int val) {
        if (s.empty()) {
            min = val;
            s.push(val);
        } else if (val >= min) {
            s.push(val);
        } else {
            s.push(2l * val - min);  // order matters here.
            min = val;
        }
    }

    void pop() {
        if (s.empty()) return;

        if (s.top() < min) {
            min = 2l * min - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.empty()) return -1;

        if (s.top() < min) {
            return min;
        }
        return s.top();
    }

    int getMin() {
        if (s.empty()) return -1;
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
