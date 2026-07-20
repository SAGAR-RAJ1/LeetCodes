class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int count = 0;bool a=true;
    for(int i =0 ; i<length;i++){
       if(s[i]==' '){
        a=false;
       }
       if(s[i]!=' '){
        if(a==false){
          count=1;
          a=true;
        }else{
count++;
        }
       }
       }
       return count;
    }
};