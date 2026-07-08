class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        
        int left = 0;
        int right = 0;
        int n = arr.size();
        for(int i = 0 ; i<k;i++){
             left+=arr[i];
        }

        int ans = left;

        if(k==n)return ans;
        int rightindex=n-1;
        for(int i = k-1;i>=0 ; i--){
            left = left-arr[i];
            right+= arr[rightindex];
            rightindex--;
            ans=max(ans,left+right);
        }
         return ans;
    }
};