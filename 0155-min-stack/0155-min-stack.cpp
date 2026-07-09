class MinStack {
public:  
      stack<int>s;
      multiset<int>st;
    MinStack() {

    }
    
    void push(int value) {
        s.push(value);
        st.insert(value);
        // mini = min(mini,value);
    }
    
    void pop() {
        int el = s.top();
        st.erase(st.find(el));//erase one ocurence
        s.pop();
        // mini = min(mini,el);
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
      int first = *st.begin();
      return first;
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