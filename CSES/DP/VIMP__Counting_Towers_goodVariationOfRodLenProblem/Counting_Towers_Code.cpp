#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007;
using lli = long long;

int t;
// dp table : dp[n+2][2]
vector<vector<lli>> dp(1e6+2, vector<lli> (2));

void solve(int n) {

    // bc
    dp[n+1][1] = dp[n+1][0] = 1;

    /* tabulation: move from bc to main problem i.e dp[2][0] + dp[2][1] */

    /* state: dp[i][0] = no of ways to construct the tower from floor i to n if i-1th floor has 2 vertical cells extending, sim dp[i][1] = .... if i-1th cell has 1 horizontal cell extending */

    for(int i = n; i >= 2; i--) {
        // transition
        dp[i][0] =  (4*dp[i+1][0] + dp[i+1][1]) % MOD;
        dp[i][1] = (2*dp[i+1][1] + dp[i+1][0]) % MOD;
    }
    lli ans = (dp[2][1] + dp[2][0]) % MOD;
    
    cout << ans << endl;
}

int main()
{
    cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        solve(n);
    }
    return 0;
}