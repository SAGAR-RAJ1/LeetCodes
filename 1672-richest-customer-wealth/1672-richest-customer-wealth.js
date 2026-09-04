/**
 * @param {number[][]} accounts
 * @return {number}
 */
var maximumWealth = function(accounts) {
    let m = accounts.length;
    let n = accounts[0].length;
    let ans = -Infinity;
    for(const a of accounts){
        let sum = 0;
      for(const i of a){

        sum+=i;

      }
      ans=Math.max(ans,sum);
    }

    return ans;


};