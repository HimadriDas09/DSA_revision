class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), cnt = k, len = 0;

        // r to include and l to exclude
        while(r < n) {
            // include everything till we've included extra
            if(nums[r] == 0) {
                // flip 
                cnt--;
            }

            while(l <= r && cnt < 0) {
                // cnt == 0 > k 0s flipped in window
                // cnt < 0 > more than k 0s flipped in window : so exclude
                if(nums[l] == 0) cnt++;
                l++;
            }

            // update len
            len = max(len, r-l+1);
            r++; // r rep nxt elem to include
        }
        return len;
    }
};