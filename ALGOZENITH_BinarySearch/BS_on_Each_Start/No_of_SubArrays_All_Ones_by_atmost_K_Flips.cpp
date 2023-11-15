/* Binary Array, k given => we need to find no of subarrays of all 1s which could be created by doing <= k flips of 0s to 1s in that subarray */

/* Approach: nothing fixed: starting from each ind we can generate multiple subarrays of all 1s with <= k flips i.e flips: [0,k].
So, for each ind i.e start: find out what is the farthest ending ind for that subarray i.e it would be a valid subarr if it contains <= k 0s. 
Rather than counting how many 0s in cur subarray > we can prev keep a prefix sum on 0s i.e how many 0s till this index, By how do we find farthest ind > Linear Search > But we can do a BINARY SEARCH > bcz prefixSum array is sorted in inc order > and 0s in cur subarray should be <= k and we need to find the max ind based on this. So check[] = {Y,Y,Y......Y,N,N.....N}. so find the farthest Yes */

#include<iostream>
using namespace std;
using lli = long long;

int arr[100100];
int pref[100100];
int n, k;

int check(int end, int st) {
    // check if x could be an end or not
    // check if cur subarray contains <= k 0s => 1 else 0

    // M1)
    // int till_end = pref[end], till_one_before_st = 0;
    // if(st != 0) till_one_before_st = pref[st-1];
    // return ((till_end - till_one_before_st) <= k);

    // M2)
    return (pref[end]-((st > 0)? pref[st-1]: 0)) <= k;
    /* to find # of 0s in subarr: if st > 0 then subtract pref[st-1] else subtract 0 */
}

int main()
{
    cin >> n >> k;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        // compute the prefix Sum on 0s
        cnt += (arr[i] == 0);
        pref[i] = cnt;
    }

    lli subarr_cnt = 0;
    // BS on each start
    for(int st = 0; st < n; st++) {
        /* for st: find the farthest end, such that subarr contains <= k 0s (that can be flipped to find max len subarr of all 1s from st, based on this we can find the subarr cnt) 
        to find the farthest end: search space is st.....n-1 */
        int lo = st, hi = n-1, ans = st-1;
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(check(mid,st)) {
                // save ans and search right for farthest
                ans = mid;
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        // got the farthest end in ans > no of subarrays is end-st+1
        subarr_cnt += ans-st+1;
    }

    cout << "ans: " << subarr_cnt << endl;
    return 0;
}

/*NOTE:
1) 
what if you've calculated prefSum on 1s and Need prefix Sum on 0s in a subarray
so we can Do: No of 0s in Subarr = (size of Subarray-(no of 1s in that SubArr using prefixSum))


*/