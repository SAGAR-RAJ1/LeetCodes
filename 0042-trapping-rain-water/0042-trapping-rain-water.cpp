class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size();
        int left[n],right[n];
        left[0]=0;
        right[n-1]=0;

        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],height[i-1]);
            
        }
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i+1]);

        }
        int water=0;int minheight=0;

        for(int i=0;i<n;i++){
            minheight=min(right[i],left[i]);
            if(minheight-height[i]>=0){

                 water+=(minheight-height[i]);
            }
           

        }
        return water;
        
    }
};