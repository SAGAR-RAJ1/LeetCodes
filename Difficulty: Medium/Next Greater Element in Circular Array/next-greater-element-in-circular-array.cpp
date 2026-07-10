class Solution {
  public:
    vector<int> nextGreater(vector<int> &nums) {
        // code here
        int n = nums.size();
        stack<int>s;
        vector<int>ans(n);
        for(int i = n-1 ; i>=0 ; i--){
            while(!s.empty() && nums[i]>=s.top())s.pop();
            s.push(nums[i]);
        }
        for(int i = n-1 ; i>=0 ; i--){
            while(!s.empty() && nums[i]>=s.top())s.pop();
            
            if(s.empty())ans[i]=-1;
            else ans[i]=s.top();
            s.push(nums[i]);
            
            
        }
        return ans;
    }
};