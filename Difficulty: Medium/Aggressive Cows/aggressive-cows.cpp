class Solution {
  public:
    bool canput(vector<int> &arr, int k,int diff){
        
        int curr=1 ; int last = arr[0];
        
        for(int i = 1 ; i<arr.size();i++){
            
            if(arr[i]-last>=diff){
                curr++;
                last = arr[i];
            }
        }
        
        if(curr>=k)return true;
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int low = 1;
        int high = arr[n-1]-arr[0];
        
        int ans = INT_MIN;
        
        
        while(low<=high){
            
            int mid = low + (high-low)/2;
            
            if(canput(arr,k,mid)){
                ans=max(ans,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};