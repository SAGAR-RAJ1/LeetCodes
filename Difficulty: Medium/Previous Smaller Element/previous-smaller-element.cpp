class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int>ans(n);
        
        stack<int>s;
        
        for(int i = 0;  i<n;i++){
            
            while(!s.empty() && s.top()>=arr[i])s.pop();
            
            if(s.empty()){
                ans[i]=-1;
            }else{
                ans[i]=s.top();
            }
            
            s.push(arr[i]);
        }
        
        
        return ans;
    }
};