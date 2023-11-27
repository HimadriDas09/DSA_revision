#include<bits/stdc++.h>
using namespace std;
#define maxlimit 10000000 /* bcz 1 <= n <= 1e6: so max no of steps cannot exceed 1e6; so we keep maxlimit as 1e7 which couldn't be an answer */

int n;

void solve() {
    vector<int> dp(n+1, maxlimit);

    // bc: all nos < 10: min steps reqd to reduce them is 1
    // or bc: could be dp[0] = 0; no of steps to go from 0 to 0 is 0
    dp[0] = 0;

    for(int no = 1; no <= n; no++) {
        // find dp[no]: state

        // transition
        int num = no, min_steps = maxlimit; 

        while(num > 0) {
            int digit = num % 10;
            num /= 10;

            min_steps = min(min_steps, dp[no-digit]);
            /* NOTE: further explore: can dp[no-digits] can be maxlimit or not */
        }
        dp[no] = 1 + min_steps;
    }

    cout << dp[n] << endl;
}

int main()
{
    cin >> n;
    solve();
    return 0;
}