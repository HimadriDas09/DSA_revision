// DICE COMBINATION: no of ways to express 'n' by throwing a dice. 

#include <iostream>
#include <vector>
using namespace std;
using lli = long long;

lli mod = 1e9 + 7;
int n;

// returns no of ways to reduce ind to 0
lli f(int ind, vector<lli> &dp) {
    
    if(ind < 0) return 0;
    if(ind == 0) return 1;
    
    if(dp[ind] != -1) return dp[ind];
    
    lli totways = 0;
    for(int i = 1; i <= 6; i++) {
        // f(ind-i): no of ways to reduce ind-i to 0 and earlier we reduced ind to ind-i in 1 way
        totways += f(ind-i, dp);
    }
    
    return dp[ind] = totways % mod;
}

void solve(int n) {
    vector<lli> dp(n+1, -1);
    // lli ans = f(n, dp);
    // cout << ans << endl;
    // return;
    
    dp[0] = dp[1] = 1;
    
    for(int ind = 2; ind <= n; ind++) {
        
        lli totways = 0;
        for(int i = 1; i <= 6; i++) {
            if(ind - i >= 0) {
                totways += dp[ind-i];
            }
        }
        
        dp[ind] = totways % mod;
    }
    
    cout << dp[n] << endl;
}

int main()
{
    cin >> n;
    
    solve(n);
    
    return 0;
}