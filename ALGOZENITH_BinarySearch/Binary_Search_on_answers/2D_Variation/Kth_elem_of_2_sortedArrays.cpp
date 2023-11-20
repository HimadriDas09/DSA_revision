/* find kth elem of the merged sorted array.
- so elem at kth posn: there should be exactly (k-1) smaller than it.
- the kth elem could be in either a1 or a2.
- BS on answers: lo = min(a1,a2), hi = max(a1,a2)

- now check[]: ..00000011111...
    - kth elem should only return 1, else all 0
    now when will the check fn return 1
    check(x): is x the kth elem? : also if x is not present then x 
    cannot be kth elem, so
    :(if no of elem which are <= x are >= k then return 1) else 0
 */
int upperBound(int x, vector<int>& a, int n) {
    int lo = 0, hi = n-1, ans = -1;
    // no of elem <= x in a: ..1111100000...
    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(a[mid] <= x) {
            ans = mid;
            // check right
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return ans+1; // ans contains index
}
int check(int x, int k, vector<int>&a, vector<int>&b, int n, int m) {
    /* (# of elem <= x) >= k then return 1 else 0
    and we need to find the pos of leftmost 1 */
    return (upperBound(x,a,n)+upperBound(x,b,m)) >= k;
}
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    int lo = min(arr1[0], arr2[0]), hi = max(arr1[n-1], arr2[m-1]);
    int ans = -1; // when bs fails i.e ...0000000... 
    /* i.e k > n+m: not possible acc to constraints */

    while(lo <= hi) {
        int mid = (lo+hi)/2;
        if(check(mid, k, arr1, arr2, n,m)) {
            ans = mid;
            hi = mid-1;
        }
        else {
            lo = mid+1;
        }
    }
    return ans;
}