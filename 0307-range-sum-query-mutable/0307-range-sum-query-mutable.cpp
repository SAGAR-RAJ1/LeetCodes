class NumArray {
public:
    vector<int> A, seg;
    int n;

    NumArray(vector<int>& nums) {
        A = nums;
        n = nums.size();
        seg.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int index, int val) {
       mineupdate(0,index,val,0,n-1);
    }

    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
    void build(int node, int l, int r) {
        if (l == r) {
            seg[node] = A[l];
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);

        seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }
    int query(int node, int l, int r, int ql, int qr) {

        if (r < ql || l > qr)
            return 0;

        if (l >= ql && r <= qr)
            return seg[node];

        int mid = l + (r - l)/2;

        return query(2*node+1,l,mid,ql,qr)+query(2*node+2,mid+1,r,ql,qr);
    }
    void mineupdate(int node , int idx , int val , int l , int r){
        if(l==r){
            A[idx]=val;
            seg[node]=val;
            return ;
        }

        int mid = l +(r-l)/2;

        if(idx>=l && idx<=mid){
            mineupdate(2*node+1,idx,val,l,mid);
        }else{
             mineupdate(2*node+2,idx,val,mid+1,r);
        }

         seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */