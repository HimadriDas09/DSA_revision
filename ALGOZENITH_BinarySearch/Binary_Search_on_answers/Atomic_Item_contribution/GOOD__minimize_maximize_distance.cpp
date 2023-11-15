/* minimize the maximum distance:
n points in sorted order, place atmost k pts in different locations, such that the maximium distance between 2 consecutive
pts is minimum: return this minimum distance */

/* constraints: 2 <= n <= 1e5, 0 <= k <= 1e9, 0 <= arr[i] <= 1e9 */

/* minimizing the maxima: BS on answers: 
minimum(maximum disance between 2 consecutive pts): check[]: ...0000000111111.....: find location of 1st occurence of 1: 
maximum distance between 2 consecutive pts: lo(since k could be 0, so lo = min distance between arr[i] and arr[i+1] BUT after
placing some pts: it might dec so lo = 1(NOT 0 bcz all distinct +ve pts), and hi = max distance between arr[i] and arr[i+1]) and after putting pts
it'd only inc: so it's a good upper limit */

#include <iostream>
#include<climits>
using namespace std;
using lli = long long;

int arr[100100];
int n,k;

int check(int x) {
    /* maintain a maximum distance of x between 2 consecutive pts by using <= k points */
    lli reqd_pts = 0;
    for(int i = 1; i < n; i++) {
        int dist = arr[i]-arr[i-1];
        if(dist > x) {
            if(dist % x == 0) {
                reqd_pts += ((dist/x)-1);
            }
            else {
                reqd_pts += (dist/x);
            }
        }
    }
    return reqd_pts <= k;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        
        int lo = 1, hi = 0;
        int ans = -1; // what if you can't find a single 1 
        /* since lo is possible: so there'll always be an ans: so it doesn't matter */
        
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            if(i > 0) {
                // lo = min(lo, arr[i]-arr[i-1]);
                hi = max(hi, arr[i]-arr[i-1]);
            }
        }
        
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(check(mid)) {
                // save and check left
                ans = mid;
                hi = mid-1;
            }
            else {
                // check right for 1 
                lo = mid+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}