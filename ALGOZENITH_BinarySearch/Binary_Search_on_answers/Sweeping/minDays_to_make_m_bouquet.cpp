// similar to painters partition
/* TC: O(search space * check)
O(maxDay-minDay+1 * n) */
class Solution {
public:
    int check(int mid, int m, int k, vector<int> &bloomDay, int n) {
        // can we form m bq(each containing k adjacent flowers) in mid days? 
        int bq_count = 0, flower_collected = 0;
        for(int i = 0; i < n; i++) {
            // what to do about ith flower
            if(bloomDay[i] <= mid) {
                // ith flower bloomed till mid days: so pick
                flower_collected++;
                if(flower_collected == k) {
                    bq_count++;
                    flower_collected = 0; // to form the next bq
                }
            }
            else {
                /* ith flower not bloomed till mid days: so cannot pick
                it cannot be a part of bq(be there any flower or not):
                so drop flowers and start new bq from next flower */
                flower_collected = 0;
            }
        }
        // traversed through all the flowers
        // if created >= m bq check
        return bq_count >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       int n = bloomDay.size();

       int maxDay = INT_MIN, minDay = INT_MAX;
       for(int i = 0; i < n; i++) {
           // till maxDay all flowers bloom : so we can easily make m bq
           // till minDay no flower bloom: lo >= minDay always
           maxDay = max(maxDay, bloomDay[i]);
           minDay = min(minDay, bloomDay[i]);
       }
       int lo = minDay, hi = maxDay, ans = -1;
       while(lo <= hi) {
           int mid = (lo+hi)/2;
           if(check(mid, m, k, bloomDay, n)) {
               // save ans and check left for better ans
               ans = mid;
               hi = mid-1;
           }
           else {
               // check right for 1
               lo = mid+1;
           }
       }
       return ans;
    }
};