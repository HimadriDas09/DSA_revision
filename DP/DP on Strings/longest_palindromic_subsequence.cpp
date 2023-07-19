#include <bits/stdc++.h> 
//tabulation approach : 
/* dp[i][j] => len of longest common subsequence in str1[0...i] and
str2[0...j] */
int LCS(string &s, string &t) {
    int n = s.length();

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    //even though all elem are 0 still write the BC
    for(int i = 0; i < n+1; i++) dp[0][i] = 0;
    for(int i = 0; i < n+1; i++) dp[i][0] = 0;
    
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < n+1; j++) {
            //match
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            //not match
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    /* len of Longest Palindromic Subsequence is len of 
    Longest Common Subsequence in 2 strings which are both reverse 
    of each other */
    string t = s;
    reverse(t.begin(), t.end());
    return LCS(s, t);
}