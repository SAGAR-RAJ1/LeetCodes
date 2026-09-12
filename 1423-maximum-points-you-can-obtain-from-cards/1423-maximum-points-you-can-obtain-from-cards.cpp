class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int left = 0;
        int right = 0;
        int n = arr.size();

        for(int i = 0 ; i<k;i++){
            left+=arr[i];
        }

        if(k==n)return left;
        int ans=left;

        int rightindex=n-1;
        for(int i = k-1 ; i>=0 ; i--){

            left-=arr[i];
            right+=arr[rightindex];

            ans=max({ans,left+right});
            rightindex--;
        }

        return ans;
    }
};