class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int left= 0 ;
        int right =0 ;

        for(int i = 0 ; i<k ; i++)left+=arr[i];

        int n = arr.size();
        if(k==n)return left;
        int ans = left;
        int rightindex=n-1;
        for(int i = k-1;i>=0;i--){
            left-=arr[i];
            right+=arr[rightindex];
            rightindex--;
            ans=max(ans,left+right);
        }
        return ans;

    }
};