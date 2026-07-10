class Solution {
	public:
	vector<int> reducePairs(vector<int>& arr) {
		stack<int> s;
		
		for (int x : arr) {
			
			while (!s.empty() &&
			((s.top() > 0 && x < 0) ||
			(s.top() < 0 && x > 0))) {
				
				if (abs(s.top()) > abs(x)) {
					x = s.top();
					s.pop();
				}
				else if (abs(s.top()) < abs(x)) {
					s.pop();
				}
				else {
					s.pop();
					x = 0;
					break;
				}
			}
			
			if (x != 0)
				s.push(x);
		}
		
		vector<int> ans(s.size());
		
		for (int i = ans.size() - 1; i >= 0; i--) {
			ans[i] = s.top();
			s.pop();
		}
		
		return ans;
	}
};
