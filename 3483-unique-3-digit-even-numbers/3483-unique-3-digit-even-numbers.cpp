class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        vector<int> count(10, 0);

        // Count frequency of each digit
        for (int d : digits) {
            count[d]++;
        }

        int ans = 0;

        // Hundreds digit: 1-9
        for (int i = 1; i <= 9; i++) {

            // Tens digit: 0-9
            for (int j = 0; j <= 9; j++) {

                // Units digit: must be even
                for (int k = 0; k <= 8; k += 2) {

                    vector<int> used(10, 0);

                    used[i]++;
                    used[j]++;
                    used[k]++;

                    bool possible = true;

                    for (int d = 0; d <= 9; d++) {
                        if (used[d] > count[d]) {
                            possible = false;
                            break;
                        }
                    }

                    if (possible)
                        ans++;
                }
            }
        }

        return ans;
    }
};