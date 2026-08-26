class Solution {
  public:
    bool doesRepresentBST(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        if(n==1)return true;
        
        for(int i = 1 ; i<n ; i++){
            if(arr[i]<arr[i-1])return false;
        }
        
        return true;
    }
};