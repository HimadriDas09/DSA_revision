/* QUESTION : 
coordinates are given along the x axis, place all k points along the axis so that the maximum distance between neighbours can be minimized(we can also place a point above another)
*/
#include<iostream>
using namespace std;

int arr[100100];
int n, k;

int check(int x) {
    /* keeping the max neighbour distance <= x (not = x bcz x exactly might not be an answer so check might return 0 when we need a 1) by using <= k points */
    int needed = 0;
    for(int i = 1; i < n-1; i++) {
        needed += (((arr[i]-arr[i-1])+x-1)/x)-1; /* ceil(distance/x)-1 */
    }
    return needed <= k;
}

signed main() {
    cin >> n >> k;
    
    // array elements are in sorted order
    // Or we sort them since they are coordinates in x-axis
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // hi should be max neighbour distance initially
    int lo = 0, hi = 0, ans = -1;
    for(int i = 1; i < n; i++) {
        hi = max(hi, arr[i]-arr[i-1]);
    }
    
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        
        if(check(mid) == 1) {
            // update ans && check left for better ans
            ans = mid;
            hi = mid-1;
        }
        else {
            // check right for 1st occ of 1st
            lo = mid+1;
        }
    }
    
    cout << ans << endl;
}

