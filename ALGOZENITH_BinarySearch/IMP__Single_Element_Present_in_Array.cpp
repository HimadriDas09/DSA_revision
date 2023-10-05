/* using binary Search using check function 

DESIGNING THE CHECK FUNCTION: 

-> sorted array, each elem with 2 duplicates except one
-> if an elem has duplicates besides it > then check the left and right of
the pair > if left's len is odd -> the single is present in left and vv

-> if single is present in left of (pair of arr[mid]) => then check(mid) = 1
else if it's present in right of the pair then check(mid) = 0 
bcz a/q to check[].

*/
class Solution {
public:
/* in the check fn : we feed in a val from search space and get the 
val of monotonic space */
    int check(int mid, vector<int>& nums, int n) {
        if(mid+1 < n && nums[mid] == nums[mid+1]) {
            int ll = mid, rl = n-1-(mid+1);
            if(ll % 2 == 1) {
                return 1;
            }
            else {
                return 0;
            }
        }   
        else if(mid-1 >= 0 && nums[mid-1] == nums[mid]) {
            int ll = mid-1, rl = n-1-mid;
            if(ll % 2 == 1) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            // this is the single elem
            return 1;
        }
    }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0, hi = n-1, ans = -1; // default ans for value
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(check(mid, nums, n) == 1) {
                // update ans but search left for better ans
                ans = nums[mid];
                hi = mid-1;
            }
            else {
                // search right for first 1
                lo = mid+1;
            }
        }
        return ans;
    }
};