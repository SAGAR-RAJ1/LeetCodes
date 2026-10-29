class Solution {
  public:
    vector<int> reducePairs(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int>s;
        
        for(int i =0 ; i<n; i++){
            
            if(s.empty() || (s.top()<0 && arr[i]<0) || (s.top()>0 && arr[i]>0)){
                s.push(arr[i]);
            }else{
                while(!s.empty() && abs(s.top())<abs(arr[i]))s.pop();
                
                if(!s.empty() && abs(s.top())==abs(arr[i])){
                    s.pop();
                    continue;
                }
                if(s.empty())s.push(arr[i]);
            }
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};