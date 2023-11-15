/* given binary string: find the max len subarr of all 1s formed by flipping atmost k bits from 0 to 1 */
/* constraints: 1 <= n <= 1e5, 0 <= k <= n */


/* since subarr can start from each start, and from st, to n-1: find the farthest end such that subarr(st,end)
has atmost k 0s which could be flipped: how do I know the cnt of 0s in a subarr: prefix sum on 0s

so check[]: ...111110000... : find the end for st for which you get the farthest 1 */

#include<iostream>
using namespace std;

int arr[100100];
int pref[100100]; // pref sum on 0s
int n,k;

int check(int st, int x) {
    /* for st: can x be the end of the subarr: such that subarr contains <= k 0s */
    int zero_cnt = pref[x]-(st > 0 ? pref[st-1]: 0);
    return zero_cnt <= k;
}

int main()
{
    int t; cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];

            pref[i] = (i>0 ? pref[i-1]: 0);
            if(arr[i] == 0) pref[i]++;
        }

        int maxSub = 0;// for maybe no 1s
        for(int st = 0; st < n; st++) {
            int lo = st, hi = n-1;
            int ans = st-1; /* in case: check[]: 00000000: so no ans so end of subarr starting from st is at st-1 */
            while(lo <= hi) {
                int mid = (lo+hi)/2;
                if(check(st, mid)) {
                    //save ans and check right
                    ans = mid;
                    lo = mid+1;
                }
                else {
                    // check left for 1
                    hi = mid-1;
                }
            }
            // for st: ans is the len of longest subarr of cont 1s
            // find max len subarr throughtout the arr
            maxSub = max(maxSub, ans-st+1);
        }
        cout << maxSub << endl;
    }
    return 0;
}