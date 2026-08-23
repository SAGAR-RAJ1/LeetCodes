class Solution {
public:
    bool sumGame(string num) {
        int lsum = 0, rsum = 0;
        int n = num.size();

        int lq = 0, rq = 0;

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?')
                    lq++;
                else
                    lsum += num[i] - '0';
            }
            else {
                if (num[i] == '?')
                    rq++;
                else
                    rsum += num[i] - '0';
            }
        }
        // Odd number of '?' -> Alice wins
        if ((lq + rq) % 2 == 1)
            return true;

        // Cancel equal number of '?' from both sides
        int mini = min(lq, rq);

        lq -= mini;
        rq -= mini;
        // No '?' left
        if (lq == 0 && rq == 0) {
            return lsum != rsum;
        }
        // Remaining '?' are only on the left
        if (lq > 0) {
            if (lsum > rsum)return true;
            return (rsum-lsum)!=(lq*9)/2;
        }
        // Remaining '?' are only on the right
        if (rq > 0) {
            if (rsum > lsum)return true;
            return (lsum-rsum)!=(rq*9)/2;
        }
    //dummy return
        return true;
    }
};