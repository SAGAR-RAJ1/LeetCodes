class Solution {
	public:
	vector<vector<int>> fourSum(vector<int> &arr, int target) {
		// code here
		int n = arr.size();
		
		set<vector<int>>s;
		if (n<4)return {};
		sort(arr.begin(), arr.end());
		for (int i = 0 ; i<n ; i++) {
			if (i>0 && arr[i] == arr[i - 1])continue;
			for (int j = i + 1 ; j<n ; j++) {
				
				int k = j + 1;
				int l = n - 1;
				
				while (k<l) {
					long long sum = (long long)arr[i]+arr[j]+arr[k]+arr[l];
					
					if (sum>target) {
						l--;
					} else if (sum<target) {
						k++;
					} else {
						vector<int>temp = {arr[i], arr[j], arr[k], arr[l]};
						sort(temp.begin(), temp.end());
						s.insert(temp);
						
						k++; l--;
						while (k<l && arr[k] == arr[k - 1])k++;
						while (k<l && arr[l] == arr[l + 1])l--;
					}
				}
				
			}
		}
		vector<vector<int>> ans(s.begin(),s.end());
		return ans;
	}
};
