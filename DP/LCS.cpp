/* length of Longest Common Subsequence => eg : "adebc", "dcadb" ans : "adb" */

/* DP on strings : approach : match and not match */

//BRUTE FORCE : 
int LCS(int ind1, int ind2) {
    //bc
    if(ind1 < 0 || ind2 < 0) return 0;

    //sc 
    //match
    if(str1[ind1] == str2[ind2]) {
        return LCS(ind1-1, ind2-1);
    }
    
    return max(LCS(ind1-1, ind2), LCS(ind1, ind2-1));
    /* why are we keeping ind1 const and ind2-1 bcz elem at ind2-1 might match
    with ind1, even if it does then in next RC, (ind2-1)-1 might match with ind1,
    so we're exploring all possible subsequences */
}
//TC : O(2^n * 2^m), SC : aux stack space : O(ht of tree)


//TABULATION : 
/* shifting of ind is done, bcz we can't rep ind == -1 in tab table
so ans of dp[-1] is stored in dp[0] && ans of dp[n-1] stored in dp[n] 
&& ans of f(i,j) => stored in dp[i+1][j+1] */

int tab(int str1, int str2) {

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

    //oth row and oth col : all elem are 0

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            /* storing ans in dp[i][j] => LCS of str1[0...i-1] && LCS of str2[0...j-1] */
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}