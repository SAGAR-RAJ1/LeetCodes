class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        //  code here
        stack<int>s;
        vector<int>ans;
        
        for(auto &a:arr){
            
            while(!s.empty() && a<=s.top())s.pop();
            
            if(s.empty()){
                ans.push_back(-1);
            }else{
                 ans.push_back(s.top());
            }
            
            s.push(a);
        }
        
        return ans;
    }
};