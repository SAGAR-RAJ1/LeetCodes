class Solution {
  public:
    int totalElements(vector<int> &fruits) {
        // code here
        
        int start = 0;
        int end = 0;
        int ans = 0;
        int n = fruits.size();
        unordered_map<int, int> m;

        while (end < n) {
            m[fruits[end]]++;

            if (m.size() > 2) {
                while (m.size() > 2) {
                    m[fruits[start]]--;
                    if (m[fruits[start]] == 0)
                        m.erase(fruits[start]); 
                    start++;
                }
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};