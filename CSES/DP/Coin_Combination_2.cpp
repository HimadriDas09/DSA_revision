#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int coins[100100];
int n,x;

void solve() {
    vector<vector<int>> dp(n, vector<int> (x+1, -1)); /* no of ways to produce a sum could be 0: which we could've calculated so by default we won't be keeping it 0 */

    /* since no of ordered ways are to be calculated i.e pick coins on the way, move to next ind or stay on the same and pick coins: So a state definition should tell that till where we've picked and what is the cur tar: so that we start picking from the same/nxt ind */

    /* dp[ind][tar]: no of distinct ordered ways to generate a sum 'tar' by collecting from index 0..ind */

    /* TABULATION: botton up approach: main problem is dp[n-1][x], so we move up to that problem from the base case */

    // bc: if(tar == 0) return 1; if(ind == 0) return (tar % coins[0] == 0) 
    for(int ind = 0; ind < n; ind++) dp[ind][0] = 1;
    for(int tar = 0; tar <= x; tar++) dp[0][tar] = (tar % coins[0] == 0);
    
    for(int ind = 1; ind < n; ind++) {
        for(int tar = 1; tar <= x; tar++) {
            // find dp[ind][tar]: state

            // transition:
            if(tar-coins[ind] >= 0) dp[ind][tar] = (dp[ind-1][tar] + dp[ind][tar-coins[ind]]) % MOD;
            else dp[ind][tar] = dp[ind-1][tar];
        }
    }

    cout << dp[n-1][x] << endl;
}

int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> coins[i];

    solve();

    return 0;
}