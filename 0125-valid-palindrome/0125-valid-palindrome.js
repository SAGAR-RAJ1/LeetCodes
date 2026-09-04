/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let ans = "";

    for(const ch of s){
        if(/[a-zA-Z0-9]/.test(ch)){
             ans+=ch.toLowerCase();
        }
    }

    let left = 0;
    let right = ans.length-1;

    while(left<=right){
       
       if(ans[left]!=ans[right])return false;
       left++;right--;
    }
    
    return true;

};