class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        //better approach than old one 

        map<int,int>m;
        for(int i =0 ; i<arr.size();i++){
            int rem = target -arr[i];
            if(m.find(rem)!=m.end()){
                return {i,m[rem]};
            }

            m[arr[i]]=i;
        }

        return {};
    }
};