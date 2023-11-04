// leetcode
using lli = long long;
class Solution {
public:
    int check(int x, vector<int>& arr, int n, int h) {
        lli hr = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] < x) {
                // eat all bananas and wait for that hr
                hr++;
            }
            else {
                // find how many hrs to complete that pile
                hr += (arr[i]/x);
                if(arr[i] % x != 0) hr++;
            } 
        }
        /* whatever hrs it took to complete all piles, if <= h : 
        check(x) == 1 */
        return hr <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int min_bananas = INT_MAX, max_bananas = INT_MIN;
        for(int i = 0; i < n; i++) {
            min_bananas = min(min_bananas, piles[i]);
            max_bananas = max(max_bananas, piles[i]);
        }
        
        // BS on ans(rate at which to eat bananas per hr)
        /* since in an hr: i target a particular pile only, if i am finished
        with all of the ban of that pile, and time is left then I won't be 
        moving to the next pile, at max is max_ban
        since for bigger 'h', with very less rate even than min_ban, I might
        eat even the smallest pile for multiple hrs and still do it in less
        than 'h' hrs > so lo = 1*/
        int lo = 1, hi = max_bananas, ans = -1;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(check(mid, piles, n, h)) {
                ans = mid;
                // check left for 1st 1
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