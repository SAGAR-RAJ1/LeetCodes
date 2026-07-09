class SpecialStack {
	public:
	stack<pair<int, int>> s;
	int mini;
	SpecialStack() {
		// Define Stack
		mini = INT_MAX;
	}
	
	void push(int x) {
		// Add an element to the top of Stack
		mini = min(x, mini);
		s.push({x, mini});
	}
	
	void pop() {
		// Remove the top element from the Stack
		s.pop();
		if (s.empty())
			mini = INT_MAX;
		else
			mini = s.top().second;
	}
	
	int peek() {
		// Returns top element of the Stack
	   if (s.empty())
            return -1;
        return s.top().first;
	}
	
	bool isEmpty() {
		// Check if stack is empty
		return s.empty();
	}
	
	int getMin() {
		// Finds minimum element of Stack
		 if (s.empty())
            return -1;
        return s.top().second;
	}
};
