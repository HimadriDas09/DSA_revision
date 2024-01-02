#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

string str1,str2;

void solve() {
    int m = str2.size(), n = str1.size();
    // create dp array
    vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

    // state: dp[j][i] => min no of operations required to convert str2 of len j to str1 of len i

    // bc => dp[0][>0] / dp[>0][0] = min operns = add that many char to convert one string to another, dp[0][0] = 0
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++) dp[i][0] = i;
    for(int i = 1; i <= n; i++) dp[0][i] = i;

    for(int j = 1; j <= m; j++) {
        for(int i = 1; i <= n; i++) {
            // state: dp[j][i]
            // transition
            if(str1[i-1] == str2[j-1]) {
                dp[j][i] = dp[j-1][i-1];
            }
            else {
                // perform all 3 operations: i.e all possible ways
                dp[j][i] = 1 + min(dp[j-1][i], min(dp[j][i-1], dp[j-1][i-1]));
            }
        }
    }
    cout << dp[m][n] << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> str1 >> str2;
    solve();

    return 0;
}