#include<iostream>
// #include<vector>
#include<bits/stdc++.h>
using namespace std;
/* len of LIS acc to > dp[i] contains len of LIS ending at ind i */
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	vector<int> dp(n, 1), hash(n, 0);
    int maxi = 1, lastIndex = 0;
    for(int ind = 0; ind < n; ind++) {
		hash[ind] = ind;
        for(int prev = 0; prev < ind; prev++) {
            if(arr[prev] < arr[ind]) {
				/* arr[ind] can be appended to LIS ending at ind prev 
				then 1 + dp[prev] would be len of LIS ending at ind */
                // dp[ind] = max(1 + dp[prev], dp[ind]);
				if(1 + dp[prev] > dp[ind]) {
					dp[ind] = 1 + dp[prev];
					hash[ind] = prev;/* prev is the index to which we
					appended ind to create LIS ending at ind */
				}
            }
        }
        // maxi = max(dp[ind], maxi);
		if(dp[ind] > maxi) {
			maxi = dp[ind];
			lastIndex = ind;/* this could be ind at which LIS ended >
			since from here we need to backtrack in hash */
		}
    }
	//lastIndex contains ending ind of LIS
	vector<int> ans;
	ans.push_back(arr[lastIndex]);
	/* and hash[lastIndex] contains ind of prev elem of the LIS */
	while(hash[lastIndex] != lastIndex) {
		lastIndex = hash[lastIndex];
		ans.push_back(arr[lastIndex]);
	}
	reverse(ans.begin(), ans.end());
	for(auto it : ans) cout << it << " ";
	cout << endl;
	return ans;
    // return maxi;
}

int main()
{   
    int n = 6;
    vector<int> arr = {5,4,11,1,16,8};
    vector<int> ans = printingLongestIncreasingSubsequence(arr, n);
    return 0;
}