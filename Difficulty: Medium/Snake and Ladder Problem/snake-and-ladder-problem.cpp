class Solution {
	public:
	
	int minThrows(int n, vector<int>& lad, vector<int>& sn) {
		// code here
		unordered_map<int, int>m;
		
		int u = lad.size();
		int d = sn.size();
		int N = n*n;
		for (int i = 0 ; i<u ; i = i + 2) {
			m[lad[i]] = lad[i + 1];
		}
		for (int i = 0 ; i<d ; i = i + 2) {
			m[sn[i]] = sn[i + 1];
		}
		
		queue<int>q;
		q.push(1);
		vector<int>dist(N + 1, -1);
		dist[1] = 0;
		while (!q.empty()) {
			
			auto curr = q.front();
			q.pop();
			
			if (curr == N)return dist[curr];
			
			for (int i = 1 ; i <= 6; i++) {
				int next = curr + i;
				if (next>N)break;
				
				if (m.find(next) != m.end()) {
					next = m[next];
				}
				if (dist[next] == -1) {
					dist[next] = 1 + dist[curr];
					q.push(next);
				}
				
			}
			
		}
		
		return -1;
		
	}
};
