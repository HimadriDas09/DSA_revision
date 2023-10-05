#include<iostream>
using namespace std;

int n, x;
int arr[100100];

// return the value of corresponding elem from check array
int check(int mid) {
    // return arr[mid] >= x; // for lower_bound
    return arr[mid] < arr[0]; // for how many times array is rotated
}

int main()
{
    cin >> n;
    cin >> x; 
    for(int i = 0; i < n; i++) cin >> arr[i];

    // lower_bound
    int lo = 0, hi = n-1;
    int ans = -1; // for lower_bound
    // int ans = 0; // for how many times array is rotated
    while(lo <= hi) {
        int mid = (lo+hi)/2;

        // [0,0,0....1,1,1,] > find the 1st 1
        // searching in monotonic space > generated using check fn
        if(check(mid) == 1) {
            ans = mid;
            // search for better ans in left of mid
            hi = mid-1;
        }
        else {
            // check(mid) == 0 > search in right of mid
            lo = mid+1;
        }
    }
    cout << "ans: " << ans << endl;
    return 0;
}