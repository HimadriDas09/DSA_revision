#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
using lli = long long;

int n;

// tc: no of states * transition of each state
// O(n*n)*O(1)
// sc: O(n*n)

void solve(vector<vector<char>> &arr) {
    // dp to store ans to unique state
    vector<vector<lli>> dp(n, vector<lli> (n, 0));

    /* dp[i1][i2]: no of ways to go from (i1, i2) to (n-1, n-1) */
    /* tabulation: bottoms up: smallest subproblem i.e dp[n-1][n-1] to main problem i.e dp[0][0] */

    // bc
    dp[n-1][n-1] = 1;
    /* since each state depends on right, down: so start from there to what you have answer for */
    for(int r = n-1; r >= 0; r--) {
        for(int c = n-1; c >= 0; c--) {
            // find state dp[r][c]

            // transition
            if(arr[r][c] != '*') {
                // this cell is not blocked: can move to other cells
                // before moving check if outside boundary or not
                lli right = 0;
                if(c+1 < n) {
                    right = dp[r][c+1];
                }
                lli down = 0;
                if(r+1 < n) {
                    down = dp[r+1][c];
                }
                // check so that we don't change the bc
                if(r == n-1 && c == n-1) dp[r][c] = 1;
                else dp[r][c] = (right + down) % MOD; 
            }
            else {
                // this cell is blocked
                dp[r][c] = 0;
            }
        }
    }
    cout << dp[0][0] << endl;
}

int main()
{
    cin >> n;
    vector<vector<char>> arr(n, vector<char> (n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    solve(arr);
    return 0;
}