// most optimal : TC: O(2n), SC: O(1)

/* app1: using prefix and suffix sum array

app2: if we consider what portion of the array we need to consider and 
in that portion we need to minimize the no of operations i.e minimize the len
of that portion(since reducing by each len takes 1 operation only) >
so we observe that ans is => n-(maximum len of subarray whose sum = totsum-x) */

#include<bits/stdc++.h>
class Solution {
private:
// arr contains +ve integer only
    int maxLenSubarraySumK(vector<int> &nums, long long k, int n) {
        int l = 0, r = 0; // l to exclude, r to include
        int len = INT_MIN;
        long long sum = 0; // window sum

        while(r < n) {
            // inc sum : using r
            sum += nums[r];

            while(l <= r && sum > k) {
                // dec sum : using l
                sum -= nums[l];
                l++;
            }
            /* since for min len subarray: calc len inside while and for
            max len : calculate outside while */
            // now sum <= k
            if(sum == k) len = max(len, r-l+1);
            r++; 
        }
        // if len == INT_MIN > then no subarray with sum k
        // len == 0 > 0 len subarray of sum 0
        return len == INT_MIN ? -1 : len;
    }

public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        long long totsum = 0;
        for(int i = 0; i < n; i++) totsum += nums[i];
        // find maxLenSubarray of sum = totSum - x
        int len = maxLenSubarraySumK(nums, totsum-x, n);
        /* if len == -1 > not possible to get a subarray of sum = totsum - x 
        else it's possible */
        return len == -1 ? -1 : n-len;
    }
};