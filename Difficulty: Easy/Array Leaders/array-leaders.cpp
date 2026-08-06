class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int>ans;
        int n = arr.size();
        ans.push_back(arr[n-1]);
        int currmax=arr[n-1];
        for(int i = n-2;i>=0;i--){
            
            if(arr[i]>=currmax){
                ans.push_back(arr[i]);
                currmax=arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};