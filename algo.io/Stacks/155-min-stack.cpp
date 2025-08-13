class MinStack {
private:
    stack<int> x;
    stack<int> min_val;
public:
    MinStack() {
    }
    
    void push(int val) {
        // check if stack is empty and assign the first value as min val
        if(MinStack::x.empty()){
            MinStack::min_val.push(val);
        }
        // check if the new value is the new minimum
        else if(MinStack::min_val.top() > val)
        MinStack::min_val.push(val);
        // else push the same minimun top again
        else{
            int top = MinStack::min_val.top();
            MinStack::min_val.push(top);
        }
        // push the value to the main stack
        MinStack::x.push(val);
    }
    
    void pop() {
        MinStack::x.pop();
        MinStack::min_val.pop();
    }
    
    int top() {
        return MinStack::x.top();
    }
    
    int getMin() {
        return MinStack::min_val.top();
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
