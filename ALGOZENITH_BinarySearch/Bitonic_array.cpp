// find the peak elem
#include<iostream>
using namespace std;

int arr[100100];
int n;

// bitonic array
int check(int mid) {
    if(mid == n-1) return 1;
    if(arr[mid] > arr[mid+1]) return 1;
    return 0;
} 

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int lo = 0, hi = n-1, ans;
    
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
