#include <bits/stdc++.h> 

int canYouMake(string &str, string &ptr)
{
    // Write your code here.

    /*APPROACH : s1 = "abcd" && s2 = "anc" => LCS is "ac" => so add "n" to s1 and "bd" to s2 OR delete "bd" from s1 and add "n" OR delete "n" from s2 and add "bd" to it , etc.... => ALL REQUIRE 3 opern to make both of them same =
    i.e (4-2) + (3-2) == 3 operations*/

    int n = str.length(), m = ptr.length();
    int LCS_len = LCS(str, ptr);

    return (n - LCS_len + m - LCS_len);
}


int LCS(string &text1, string &text2){
    int n = text1.size();
    int m = text2.size();
    vector<int> prev(m+1, 0), cur(m+1, 0);

    // for(int i = 0; i <= n; i++) dp[i][0] = 0;
    // for(int j = 0; j <= m; j++) dp[0][j] = 0;

    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= m; j++){
            if(text1[i-1] == text2[j-1]) cur[j] = 1 + prev[j-1];
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
    return prev[m];
}
