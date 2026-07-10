class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        int leftmax[n]={0};
        int rightmax[n]={0};
        
        leftmax[0]=arr[0];
        for(int i = 1 ; i<n;i++){
            leftmax[i]=max(arr[i],leftmax[i-1]);
        }
        rightmax[n-1]=arr[n-1];
        for(int i = n-2 ; i>=0;i--){
            rightmax[i]=max(arr[i],rightmax[i+1]);
        }
        int ans = 0;
        for(int i = 0 ; i<n;i++){
            int can=min(rightmax[i],leftmax[i])-arr[i];
            if(can>0)ans+=can;
        }
        return ans;
    }
};