#include<iostream>
using namespace std;
#define int long long

int arr[100100];
int n,t;

int check(int mid) {
    // can we create atleat t products in mid time
    int total_produced = 0;
    for(int i = 0; i < n; i++) {
        // arr[i] time = 1 product => mid time = mid/arr[i] product
        total_produced += mid/arr[i];
    }
    if(total_produced >= t) return 1;
    return 0;
}

signed main()
{
    cin >> n >> t;

    for(int i = 0; i < n; i++) cin >> arr[i];

    // search space of time > hi: to produce all the t products by 0th machine only which produce 1 product in arr[0] time > t product in t*arr[0]
    int lo = 0, hi = t*arr[0], ans = -1;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(check(mid)) {
            // save ans = mid and search left for better ans
            ans = mid;
            hi = mid-1;
        }
        else {
            // search right for 1
            lo = mid+1;
        }
    }
    cout << ans << endl;

    return 0;
}