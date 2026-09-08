class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int low =1;
        int high=m;
        int ans = -1;
        
        if(m<2)return m;
        
        while(low<=high){
            int mid = low+(high-low)/2;
            int curr=1;
            for(int i= 0 ; i< n ; i++){
                curr*=mid;
            }
            
            if(curr==m){
                return mid;
            }else if(curr>m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};