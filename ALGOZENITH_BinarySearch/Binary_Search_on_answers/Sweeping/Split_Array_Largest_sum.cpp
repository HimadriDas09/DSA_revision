// leetcode:
// Binary Search on Answer > Sweep
using lli = long long;
class Solution {
public:
    int check(lli mid, vector<int>& nums, int k, int n) {
        /* (check if <= k subarrays can be formed with each having a sum
        of <= mid), return 1 else 0 */

        lli no_of_partition = 1, sum_of_cur_partition = 0;

        for(int i = 0; i < n; i++) {
            /* nums[i] be a part of cur partition or a new partition ?? */
            if(sum_of_cur_partition + nums[i] <= mid) {
                sum_of_cur_partition += nums[i];
            }
            else {  
                // create a new partition
                no_of_partition++;
                sum_of_cur_partition = 0;
                if(no_of_partition > k) return 0;
                
                if(sum_of_cur_partition + nums[i] <= mid) {
                    sum_of_cur_partition += nums[i];
                }
                else {
                    /* nums[i] couldn't be a part of any partition,
                    provided we can at max allot mid to be sum of partition */
                    return 0;
                }
            }
        }
        return 1;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        lli tot_sum = 0;
        for(int i = 0; i < n; i++) tot_sum += nums[i];

        // bs on answer > answers is sum of subarray
        lli lo = 0, hi = tot_sum, ans = -1;

        while(lo <= hi) {
            lli mid = (lo + hi)/2;
            if(check(mid, nums, k, n)) {
                // update ans and check left for 1st apperance of one
                ans = mid;
                hi = mid-1;
            }
            else{
                // check right for 1
                lo = mid+1;
            }
        }
        return (int) ans;
    }
};