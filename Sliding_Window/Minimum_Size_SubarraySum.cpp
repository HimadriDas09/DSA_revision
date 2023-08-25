/* asked to find the min len subarray whose sum of elem >= target*/
/* approach: ⇒ Sliding Window: l = 0, r = 0, include elem using r > check if (sum ≥ target) { then update the len } and r++CONSIDER that now r rep then NXT elem to include in our subarray > do above suing while() till our sum ≥ target. NOW we won’t be inc the len of that subarray bcz we need min len subarray. NOW explore subarrays ending at r-1, within that subarray only, by excluding elem via the left pointer. so exclude elem now check if (cur subarray sum ≥ target ) {  update the len }, do this in while() till sum < target : now we need to include more elem in our subarray using r. */
// TC: O(2n) SC: O(1)
#include<bits/stdc++.h>
int minSubArrayLen(int target, vector<int>& nums) {
    int i=0;
    int j=0; // i left pointer, j right pointer for sliding window
    int sum=0;
    int mn=INT_MAX; // len
    while(j<nums.size()){
        sum+=nums[j];
            /* after adding when sum >= target then only we need to calculate the len
            after calculaing len, we do left++ till sum < target: then we do right++
            and include that elem */
        while(sum>=target){
            sum-=nums[i];
            mn=min(j-i+1,mn);
            i++;
        }
        j++;
    }
    if(mn==INT_MAX){
        return 0;
    }
    return mn;
}