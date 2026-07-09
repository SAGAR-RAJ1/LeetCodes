class MinStack {
public:  
      stack<pair<int, int>> s;
	int mini;
    MinStack() {
  mini = INT_MAX;
    }
    
    void push(int x) {
        mini = min(x, mini);
		s.push({x, mini});
    }
    
    void pop() {
        	s.pop();
		if (s.empty())
			mini = INT_MAX;
		else
			mini = s.top().second;
    }
    
    int top() {
        	 if (s.empty())
            return -1;
        return s.top().first ;
    }
    
    int getMin() {
      	 if (s.empty())
            return -1;
        return s.top().second;
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