#include<iostream>
using namespace std;

int arr[10101];
int n, x;

// check fn:
// 1 1 1 ... 1 0 . . .0 
// find the rightmost 1 > this way is useful in this problem
int check(int mid) {
    return mid*mid <= n;
}
/* eg: n = 12 > 1 2 3 4 5 6 
> check(mid) > 1 1 1 0 0 0
since square root is <= n/2 */


int main()
{
    cin >> n;

    int lo = 1, hi = n>>1, ans = 1;
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(check(mid)) {
            // save ans and find the righmost 1
            ans = mid;
            lo = mid+1;
        }
        else {
            // move left to find 1
            hi = mid-1;
        }
    }
    cout << ans << endl;
    return 0;
}