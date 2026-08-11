class MinStack {
public:
    stack<int> st, minStack;
    MinStack() {
        
    }
    
    void push(int val) {
        int currMin = minStack.empty() ? val : min(minStack.top(), val);
        st.push(val);
        minStack.push(currMin);
        
    }
    
    void pop() {
        st.pop();
        minStack.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
