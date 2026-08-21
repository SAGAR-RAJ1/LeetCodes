class Solution {
  public:
  
   vector<int>seg;
   vector<int>A;
   void build(int node , int l , int r){
       
       if(l==r){
           seg[node]=A[l];
           return;
       }
       int mid = l+(r-l)/2;
       build(2*node+1,l,mid);
       build(2*node+2,mid+1,r);
       
       
       seg[node]=seg[2*node+1]+seg[2*node+2];
    
   }
   
   int query(int node , int ql , int qr, int l ,int r ){
       
       if(qr<l || ql>r)return 0;
       
       if(ql<=l && qr>=r)return seg[node];
       
       int mid = l + (r-l)/2;
       
       int left = query(2*node+1,ql,qr,l,mid);
       int right = query(2*node+2,ql,qr,mid+1,r);
       
       return left+right;
       
   }
   
   void update(int node , int idx , int val , int l ,int r){
       
       if(l==r){
           A[idx]=val;
           seg[node]=val;
       }else{
           
           int mid = l + (r-l)/2;
           
           if(idx>=l && idx<=mid){
               //left
               update(2*node+1,idx,val,l,mid);
           }else{
                update(2*node+2,idx,val,mid+1,r);
           }
           
            seg[node]=seg[2*node+1]+seg[2*node+2];
       }
   }
    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        int n = arr.size();
        A=arr;
        seg.resize(4*n);
        vector<int>ans;
        build(0,0,n-1);
        for(auto &a:queries){
            int type = a[0];
            
            if(type==1){
                int start = a[1];
                int end = a[2];
                
                ans.push_back(query(0,start,end,0,n-1));
            }else{
                int idx = a[1];
                int val = a[2];
                
                update(0,idx,val,0,n-1);
            }
        }
        
        return ans;
        
    }
};