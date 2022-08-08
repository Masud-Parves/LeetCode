class MinStack {
private:
    stack<int>main;
    stack<int>minVal;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        main.push(val);
        
        if(minVal.empty() || minVal.top()>=val){
            minVal.push(val);
        }
    }
    
    void pop() {
        if(main.empty()) return;
        int val = main.top();
        main.pop();
        if(!minVal.empty() && val == minVal.top()){
            minVal.pop();
        }
        return;
    }
    
    int top() {
        if(main.empty()) return 0;
        return main.top();
    }
    
    int getMin() {
        if(minVal.empty()) return 0;
        int minValue = minVal.top();
        return minValue;
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