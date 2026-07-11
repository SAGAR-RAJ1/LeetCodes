class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int>ans;
        int n = arr.size();
        deque<pair<int,int>>dq;
        
        for(int i = 0 ; i< n ; i++){
             
             if(!dq.empty() && dq.front().first<=i-k)dq.pop_front();
             
             while(!dq.empty() && dq.back().second<=arr[i])dq.pop_back();
             
             dq.push_back({i,arr[i]});
             
             if(i>=k-1)ans.push_back(dq.front().second);
        }
        return ans;
    }
};