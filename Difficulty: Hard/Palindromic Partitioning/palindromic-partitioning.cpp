 class Solution {
 public:
     vector<vector<int>> dp; vector<vector<int>> pal;

bool isPalindrome(string &s, int i, int j) {

    int originalI = i;
    int originalJ = j;

    if (pal[originalI][originalJ] != -1)
        return pal[originalI][originalJ];

    while (i < j) {

        if (s[i] != s[j])
            return pal[originalI][originalJ] = false;

        i++;
        j--;
    }

    return pal[originalI][originalJ] = true;
}

     int solve(string &s, int i, int j) {

         if (i >= j)
             return 0;

         if (dp[i][j] != -1)
             return dp[i][j];

         if (isPalindrome(s, i, j))
             return dp[i][j] = 0;

         int ans = INT_MAX;

         for (int k = i; k < j; k++) {

             if(isPalindrome(s,i,k)){
                 int temp = 1 + solve(s,k+1,j);
                 ans=min(ans,temp);
             }
         }

         return dp[i][j] = ans;
     }

     int palPartition(string &s) {

         int n = s.size();

         dp.assign(n, vector<int>(n, -1));
         pal.assign(n, vector<int>(n, -1));

         return solve(s, 0, n - 1);
     }
 };