/* Calculate no of distinct ways to produce a sum of money 'x' using available coins 
you can use same coins multiple times */

#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007 /* define a constant like this only, rather than int mod = 1e9+7 which may lead to some precision errors */

int coins[100100];
int n,x;

void solve() {

    vector<int> dp(x+1, 0);

    /* bc: no of distinct way to express sum 0 is 1, i.e when we reach 0 it is counted as 1 way */
    dp[0] = 1; 

    for(int tar = 1; tar <= x; tar++) {
        // dp[tar] is state
        // to find dp[tar]: no of distinct ways to rep tar as sum of coins

        // transition for state: how bigger problem is related to smaller subproblems
        for(int ind = 0; ind < n; ind++) {
            if(tar >= coins[ind]) {
                dp[tar] = (dp[tar] + dp[tar-coins[ind]]) % mod;
            }
        }
    }
    cout << dp[x] << endl;
}

int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> coins[i];

    solve();
    return 0;
}