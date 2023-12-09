#include<bits/stdc++.h>
using namespace std;
using lli = long long;

int n,x;
int prices[1000], pages[1000];

void solve() {
    vector<vector<int>> dp(n, vector<int> (x+1, 0));

    /* tabulation: botton up approach: bc i.e ind == 0 and tar == 0 to main problem i.e dp[n-1][x] */

    for(int ind = 0; ind < n; ind++) {
        for(int tar = 0; tar <= x; tar++) {
            /* state: dp[ind][tar] i.e maximum no of pages collected from 0...ind if price target is <= tar */
            
            // bc here only:
            if(ind == 0 && tar == 0) dp[ind][tar] = 0;
            else if(ind == 0) {
                if(prices[ind] <= tar) dp[ind][tar] = pages[ind];
                else dp[ind][tar] = 0;
            }
            else if(tar == 0) {
                dp[ind][tar] = 0;
            }
            else {
                // transition
                int nottake = dp[ind-1][tar];
                int take = 0;
                if(prices[ind] <= tar) {
                    take = pages[ind] + dp[ind-1][tar-prices[ind]];
                }
                dp[ind][tar] = (take > nottake) ? take : nottake;
            }

        }
    }
    cout << dp[n-1][x] << endl;
}

int main()
{
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> prices[i];
    for(int i = 0; i < n; i++) cin >> pages[i];

    solve();
    return 0;
}