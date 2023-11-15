#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

/* TC: O(log(search space)*check)
O(log(arr[n-1]-arr[0] - arr[1]-arr[0])*O(n2)) */


/*NOTE: in all online judges > it's not mentioned to always put a cow at the 0th stall > (but they accept solution only with a cow at 0th stall else complexity of check(x) is O(n2)) 

    NOTE : WRONG above note bcz since distance within the check fn has to be maximized i.e >= x, so initially say we're to keep first cow at first th pos, and 2nd cow at (first + a)th pos > now we could've kept 1st cow at 0th and 2nd at (first+a)th > then also distance maximized

    So, ans is it doesn't matter.
*/

int check(int x, int* stalls, int n, int k) {
    /* can we maintain a min distance of >= x between any 2 cows
    and place all the cows(i.e use >= k cows) */

    // explore all pos of placing the 1st cow > i.e ind 0 to n-k
    // for(int first = 0; first <= n-k; first++) {
        int cur_cow_pos = stalls[0];
        int cows_count = 1; // 1st cow

        // place rest cows and see if >= x is valid for atleast k cows
        for(int i = 0+1; i < n; i++) {
            // now to assign a cow at this stall or not
            if(stalls[i]-cur_cow_pos >= x) {
                // place cow
                cows_count++;
                cur_cow_pos = stalls[i];
            }
        }
        /* check if we used all the cows i.e >= k cows then this is 
        a valid placement of cows, maintaining a min distance of >= x
        else try rem pos of first cow */

        // if(cows_count >= k) return 1;

    // got no valid ans(for all first) > so x is not valid
    // return 0;
    return cows_count >= k;
}

int main()
{
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        int stalls[100100];
        cin >> n >> k;

        for(int i = 0; i < n; i++) cin >> stalls[i];

        /* sort for no further conflicts between min distance between 2
        cows */
        sort(stalls, stalls + n);
        int lo = stalls[1]-stalls[0], hi = stalls[n-1]-stalls[0], ans = -1;
        
        /* monotonic space : ...11110000... 
        bcz we need to maximize the min distance
        so 1 -> a valid min distance which we're maximizing till the 
        pt before it's invalid */
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(check(mid, stalls, n, k)) {
                // save ans and check right for better
                ans = mid;
                lo = mid+1;
            }
            else {
                // check left for 1
                hi = mid-1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}