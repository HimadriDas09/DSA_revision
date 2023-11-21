/* Minimizing Coins: n coins are given of infinite supply, return min no of coins reqd to add up to a sum of x  */
/* if not possible return -1 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using lli = long long; 

int coins[100100];
int n,x;

/* f(ind,tar): from 0..ind min no of coins to represent tar */
int f(int ind, int tar, vector<vector<int>> &dp) {
    // bc 
    if(tar == 0) return 0;
    // if(ind < 0 || tar < 0) return -1;
    
    if(ind == 0) {
        if(tar % coins[ind] == 0) return dp[0][tar] = tar/coins[ind];
        return -1;
    }
    
    if(dp[ind][tar] != -1) return dp[ind][tar];
    
    // sc 
    // not pick 
    int np = f(ind-1, tar, dp);
    
    int p = -1;
    // pick: can if can pick
    if(coins[ind] <= tar) {
        p = f(ind, tar-coins[ind], dp);
        if(p != -1) p += 1;
    }
    
    if(np == -1 && p == -1) return -1;
    else if (p == -1) return dp[ind][tar] = np;
    else if (np == -1) return dp[ind][tar] = p;
    
    return dp[ind][tar] = min(p,np);
}

int tabulation(vector<vector<int>> &dp) {
// tabulation: bottom up approach
    
    // bc
    for(int ind = 0; ind < n; ind++) dp[ind][0] = 0;
    for(int tar = 0; tar <= x; tar++) {
        if(tar % coins[0] == 0) dp[0][tar] = tar/coins[0];
        else dp[0][tar] = -1;
    }
    
    // nested loops:
    for(int ind = 1; ind < n; ind++) {
        for(int tar = 1; tar <= x; tar++) {
            int np = dp[ind-1][tar];
                
            int p = -1;
            // pick: can if can pick
            if(coins[ind] <= tar) {
                p = dp[ind][tar-coins[ind]];
                if(p != -1) p += 1;
            }
            
            if(np == -1 && p == -1) dp[ind][tar] = -1;
            else if (p == -1)  dp[ind][tar] = np;
            else if (np == -1)  dp[ind][tar] = p;
            else dp[ind][tar] = min(p,np);
        }
    }
    return dp[n-1][x];
}

void solve() {
    vector<vector<int>> dp(n, vector<int> (x+1, -1));

    // memoisation:
    
    // int ans = f(n-1, x, dp);
    // cout << ans << endl;
    
    int tab_ans = tabulation(dp);
    
    cout << tab_ans << endl;
}

int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> coins[i];
    
    solve();

    return 0;
}
