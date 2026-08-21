class NumArray {
public:
   vector<int>A,seg;
   int n ; 
    NumArray(vector<int>& nums) {
        n = nums.size();
        A=nums;
        seg.resize(4*n);
        build(0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }

    void build(int node , int l , int r){
        if(l==r){
            seg[node]=A[l];
            return;
        }

        int mid = l +(r-l)/2;

        build(2*node+1,l,mid);
        build(2*node+2,mid+1,r);

        seg[node]=seg[2*node+1]+seg[2*node+2];
    }
    int query(int node , int l, int r , int ql , int qr){
        
        if(l>qr || r<ql)return 0;

        if(l>=ql && r<=qr)return seg[node];

        int mid = l + (r-l)/2;

        return query(2*node+1,l,mid,ql,qr)+query(2*node+2,mid+1,r,ql,qr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */