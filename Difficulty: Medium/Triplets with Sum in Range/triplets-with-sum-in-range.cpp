class Solution {
  public:
  int countTriplets(vector<int> &arr, int l, int r) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int count1=0;//<l
        int count2=0;//<=r
        for(int start = 0 ; start<n ; start++){
            
            int second = start+1;
            int end = n-1;
            while(second<end){
                int sum = arr[start]+arr[second]+arr[end];
                
                if(sum<l){
                    count1+=end-second;second++;
                }else{
                    end--;
                }
            }
        }
          for(int start = 0 ; start<n ; start++){
            int second = start+1;
            int end = n-1;
            while(second<end){
                int sum = arr[start]+arr[second]+arr[end];
                
                if(sum<=r){
                    count2+=end-second;second++;
                }else{
                    end--;
                }
            }
        }
        return count2-count1;
    }
};