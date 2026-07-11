class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        stack<pair<int,int>>s;
        int n = arr.size();
        vector<int>ans(n);
        int index = -1;
        for(int i = 0 ; i< n ; i++){
            index+=1;
            
            while(!s.empty() && s.top().first<=arr[i])s.pop();
            
            int res = index - (s.empty()?-1:s.top().second);
            ans[i]=res;
            s.push({arr[i],index});
            
        }
        return ans;
    }
};