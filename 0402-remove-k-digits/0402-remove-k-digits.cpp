class Solution {
public:
    string removeKdigits(string arr, int k) {
        int n = arr.size();

        stack<char> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && s.top() > arr[i] && k > 0) {
                s.pop();
                k--;
            }

            s.push(arr[i]);
        }
        while (!s.empty() && k > 0) {

            s.pop();

            k--;
        }

        int size = s.size();
        string ans = "";
        while (!s.empty()) {

            ans += s.top();

            s.pop();
        }

        reverse(ans.begin(), ans.end());

        // Remove leading zeros

        int i = 0;

        while (i < ans.size() && ans[i] == '0') {

            i++;
        }

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};