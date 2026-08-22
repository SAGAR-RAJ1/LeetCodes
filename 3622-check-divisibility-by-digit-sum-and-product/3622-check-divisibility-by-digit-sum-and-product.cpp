class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int pro = 1 ;
        int sum  =0;

        while(temp>0){
            int dig = temp%10;
            pro*=dig;sum+=dig;
            temp=temp/10;
        }

        if(n%(pro+sum)==0)return true;

        return false;

    }
};