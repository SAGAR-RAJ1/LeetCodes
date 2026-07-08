class Solution {
public:
    int lengthOfLongestSubstring(string s) {


     int first =0 , second = 0 , length=0;

     vector<int>count(256,0);

     while(second<s.size()){
      
    //   while(count[s[second]]){
    //    count[s[first]]=0;
    //    first++;}
     count[s[second]]++;
    
//if repeating happens
if(count[s[second]]>1){
     
     while(count[s[second]]>1){
          
          count[s[first]]=0;
          first++;
     }
     count[s[second]]=1;
    

}

    //  count[s[second]]=1;
     length=max(length,second-first+1);
     second++;
     }
     
     return length;






        //
        
    }
};