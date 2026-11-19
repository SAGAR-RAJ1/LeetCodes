class Solution {
  public:
    
    void merge(vector<int>& arr, int l,int mid, int r) {
        // code here
       
       vector<int>temp;
       
       int i = l ; int j = mid+1;
       
       while(i<=mid && j<=r){
           
           if(arr[i]<=arr[j]){
               temp.push_back(arr[i]);
               i++;
           }else{
            temp.push_back(arr[j]);
               j++;
           }
       }
       
       while(i<=mid){
               temp.push_back(arr[i]);
               i++;
       }
       while( j<=r){
            temp.push_back(arr[j]);
               j++;
       }
       
       
       for(int i = 0; i<temp.size();i++){
           arr[i+l]=temp[i];
       }
       
       
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        
        if(l<r){
            
            int mid = l+(r-l)/2;
            
            
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            
            
            merge(arr,l,mid,r);
            
        }
        
    }
};