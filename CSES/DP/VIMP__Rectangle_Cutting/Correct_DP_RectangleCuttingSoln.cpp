#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int a,b;


/*  TIME and SPACE COMPLEXITY:
    - TC: (# of unique states) * (avg transition time of each state)
        = (a*b) * (O(b) + O(a))
        = O(a^2b + ab^2)
    - no of unique states are (a*b) && for transition time of each state => we're making all the possible ver cuts and all possible hor cuts
*/

void solve() {
    // dp table
    vector<vector<int>> dp(a+1, vector<int> (b+1, INF));

    // State: dp[i][j] => min no of moves to reduce i*j rectangle into all squares
    // by default it requires INF no of moves

    // bc: if(both len is same => it's already a square), if(either of the len is 1 => no of moves to reduce it to square is otherLen-1)

    // int minLen = min(a,b); // to go along the actual diagonal for i==j
    // for(int i = 1; i <= minLen; i++) dp[i][i] = 0;
    // for(int i = 1; i <= a; i++) dp[i][1] = i-1;
    // for(int j = 1; j <= b; j++) dp[1][j] = j-1;

    for(int i = 1; i <= a; i++) {
        for(int j = 1; j <= b; j++) {
            // i is height
            // j is width
            // transition for state: dp[i][j] => make all hor cuts Or all ver cuts
            if(i == j) {
                dp[i][j] = 0;
                continue;
            }
            // horizontal cuts
            for(int len = 1; len <= i-1; len++) {
                dp[i][j] = min(dp[i][j], 1 + dp[len][j] + dp[i-len][j]);
            }

            // vertical cuts
            for(int len = 1; len <= j-1; len++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][len] + dp[i][j-len]);
            }
        }
    }

    cout << dp[a][b] << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    cin >> a >> b;
    solve();

    return 0;
}