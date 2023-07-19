#include <bits/stdc++.h> 


int minInsertion(string &str)
{
    // Write your code here.
    /*APPROACH : eg : str1 = "abcaxy" 
    => LCS of (str1, rev(str1)) is "aca" or "aba"=> common + middle => I could just add them to make it palindrome*/
    return (str.length() - LPS(str));
}


//tabulation approach : 
/* dp[i][j] => len of longest common subsequence in str1[0...i] and
str2[0...j] */
int LCS(string &s, string &t) {
    int n = s.length();

    // vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    vector<int> prev(n+1, 0);

    //even though all elem are 0 still write the BC
    for(int i = 0; i < n+1; i++) prev[i] = 0;
    // for(int i = 0; i < n+1; i++) dp[i][0] = 0;
    
    for(int i = 1; i < n+1; i++) {
        vector<int> cur(n+1, 0);
        for(int j = 1; j < n+1; j++) {
            //match
            if(s[i-1] == t[j-1]) {
                cur[j] = 1 + prev[j-1];
            }
            //not match
            else{
                cur[j] = max(prev[j], cur[j-1]);
            }
        }
        prev = cur;
    }
    return prev[n];
}
int LPS(string s)
{
    // Write your code here.
    /* len of Longest Palindromic Subsequence is len of 
    Longest Common Subsequence in 2 strings which are both reverse 
    of each other */
    string t = s;
    reverse(t.begin(), t.end());
    return LCS(s, t);
}
