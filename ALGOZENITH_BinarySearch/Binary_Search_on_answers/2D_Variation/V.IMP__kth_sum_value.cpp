// BS on answers > 2D variation 
/* C[i] = A[i] + B[i], then find the kth value if values of C sum matrix is arranged in sorted order */

/* Since this is BS on answers only => i.e for check(x) == 1 => i.e if I should return 1 on x or 0
=> if the cnt of elements from the C matrix which are <= x are >= k then return 1 
bcz if cnt == k => then x is the kth element => then for >= k it will be 1 and we find the ans which gives the 1st occurence of 1. */

#include<bits/stdc++.h>
using namespace std;

using lli = long long;

lli n,m,k;
vector<lli> arr, brr;

/* check returns ((no of elem in C <= x) >= k), bcz to get the elem at kth pos in the sorted array of C, >= kth pos should all be 1 (&& we need to find the elem at pos of 1st one) */
/* now how do we get cnt of elem <= x in C matrix (C[i] = A[i]+B[i]) without creating the C matrix,
by traversing in A and finding which elem in B when summed with A[i] gives <= x, find cnt of those elem in B using Binary Search [considering A and B is sorted] */
int check(lli x) {
    lli cnt = 0; // cnt of no of elem in B(such that A[i] + B[i] <= x), B[i] <= x-A[i]
    for(int i = 0; i < n; i++) {
        cnt += upper_bound(brr.begin(), brr.end(), x-arr[i])-brr.begin(); // to get no of elems
    }
    return cnt>=k;
}

int solve() {
    cin >> n >> m >> k;
    arr.resize(n); // make vector arr size = n;
    brr.resize(m);

    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < m; i++) cin >> brr[i];

    // bcz we always want to traverse the smaller arr and apply bs on larger array
    if(n > m) {
        swap(n,m);
        swap(arr, brr);
    }

    // sort both
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    /* BS on ans > ans is value of sum matrix > lowest being sum of smallest and highest being sum of highest */
    lli lo = arr[0]+brr[0], hi = arr.back()+brr.back(), ans = -1;

    while(lo <= hi) {
        lli mid = (lo+hi)/2;
        if(check(mid)) {
            // save ans and check left for better 1
            ans = mid;
            hi = mid-1;
        }
        else {
            // look at right for 1
            lo = mid+1;
        }
    }
    cout << ans << endl;

    return 0;
}

int main()
{
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}