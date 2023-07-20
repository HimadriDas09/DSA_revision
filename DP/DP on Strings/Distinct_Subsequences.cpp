//Space Optimization to 1 array
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    // vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
    vector<double> prev(m+1, 0);
    prev[0] = 1;

    // for(int i = 0; i <= n; i++) dp[i][0] = 1;
    //& if(i < 0) return 0; all the elem are 0 already

    for(int i = 1; i <=n; i++) {
        for(int j = m; j >= 1; j--) {
            if(s[i-1] == t[j-1]) {
                prev[j] = prev[j-1] + prev[j];
            }
            else{
                prev[j] = prev[j];
            }
        }
    }
    return (int)prev[m];

    // return f(n, m, s, t, dp);
}


//Space Optimization to 2 arrays
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    // vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
    vector<double> cur(m+1, 0), prev(m+1, 0);
    cur[0] = prev[0] = 1;

    // for(int i = 0; i <= n; i++) dp[i][0] = 1;
    //& if(i < 0) return 0; all the elem are 0 already

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                cur[j] = prev[j-1] + prev[j];
            }
            else{
                cur[j] = prev[j];
            }
        }
        prev = cur;
    }
    return (int)cur[m];

    // return f(n, m, s, t, dp);
}


//INDEX SHIFTINT + Memoisation
int f(int i, int j, string &s, string &t, vector<vector<int>> &dp) {
    if(j == 0) return 1;
    if(i == 0) return 0;//i.e if j !< 0 && i < 0 

    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1]) {
        return dp[i][j] = f(i-1,j-1, s, t, dp) + f(i-1, j, s, t, dp);
    }
    return dp[i][j] = f(i-1, j, s, t, dp);
}

//TABULATION 
int numDistinct(string s, string t) {
    int n = s.length();
    int m = t.length();
    vector<vector<double>> dp(n+1, vector<double> (m+1, 0));

    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    //& if(i < 0) return 0; all the elem are 0 already

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return (int)dp[n][m];

    // return f(n, m, s, t, dp);
}
