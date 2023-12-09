// TC and SC

/* TC: no of states * avg transition of each state
i.e O(n*m)*O(1)
&& SC: O(n*m) for dp array */

#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define MOD 1000000007

int arr[100100];
int n,m;

bool isValid(int i) {
    return (i >= 1 && i <= m);
}

/* state: dp[i][k]: cnt of prefix arrays from (0...i) with next elem being 'k' */

void solve() {
    // tabulation approach: dp[i][k]: i from 0 to n-1 && k from 1 to m (not taking 0 bcz we're solving for all possible values of 0): dp[n][m]
    vector<vector<int>> dp(n, vector<int> (m+1, 0));

    /* bc: if ind == 0: now elem at 0th pos could be 0 or non 0: 
    if 0 => we can change it so it dp[0][k] could be cnt of valid k,k-1,k+1 : bcz that many unique prefix arrays are possible
    if it's non 0: then dp[0][k] = 1 if either arr[0] is a valid k or k-1 or k+1.
    else i.e non 0 but not valid: dp[0][k] = 0. */

    for(int k = 1; k <= m; k++) {
        if(arr[0] == 0) {
            // 0th elem is unknown value
            dp[0][k] = isValid(k-1) + isValid(k) + isValid(k+1);
        }
        else {
            // 0th elem is known value i.e k/k+1/k-1
            if((isValid(k-1) && arr[0] == k-1) || (isValid(k+1) && arr[0] == k+1) || arr[0] == k) {
                dp[0][k] = 1; // k is always valid i.e within value range: so we didn't check it earlier
            }
            else dp[0][k] = 0;
        }
    }

    for(int i = 1; i < n; i++) {
        for(int k = 1; k <= m; k++) {
            // find state: dp[i][k]

            // find transition: i.e how dp[i][k] depends on it's smaller sub states
            if(arr[i] == 0) {
                // ith elem is unknown value: so we can either put valid k/k-1/k+1 here
                dp[i][k] = dp[i-1][k];
                if(isValid(k-1)) dp[i][k] = (dp[i][k] + dp[i-1][k-1]) % MOD;
                if(isValid(k+1)) dp[i][k] = (dp[i][k] + dp[i-1][k+1]) % MOD;
            }
            else {
                // ith elem is a known value: which could either be k/k-1/k+1
                /* since ith value is constant: and if it's a valid constant i.e k/k+1/k-1: then 
                dp[i-1][constant] is same as dp[i][k] bcz just like k, constant is also fixed */
                if(arr[i] == k) dp[i][k] = dp[i-1][k];
                else if(isValid(k-1) && arr[i] == k-1) dp[i][k] = dp[i-1][k-1];
                else if(isValid(k+1) && arr[i] == k+1) dp[i][k] = dp[i-1][k+1];
                else {
                    // ith elem is not a valid value
                    dp[i][k] = 0;
                }
            }
        }
    }

    /* final ans: sum of all dp[n-2][k] for k = 1...m for k == 0 */
    int ans = 0;
    if(arr[n-1] == 0 && n >= 2) {
        for(int k = 1; k <= m; k++) {
            ans = (ans + dp[n-2][k])%MOD;
        }
    }
    else if(arr[n-1] == 0) {
        // last elem is 0 but size is < 2 i.e 1
        ans = m;
    }
    else if(n >= 2){
        // last elem != 0 && size >= 2
        ans = dp[n-2][arr[n-1]];
    }
    else {
        // size of array is 1 and last elem != 0
        ans = 1;
    }
    cout << ans << endl;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];

    solve();
    return 0;
}