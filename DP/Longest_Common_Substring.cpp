/*approach : Similar to tabulation approach of Longest Common Subsequence only :
NOW, the longest Common Substring can appear in any part of either of the strings => 

    - so look for it everywhere in the dp table(via the dp table we can explore all possible position of a substring)

    - now if a char matches => dp[i][j] = 1 + dp[i-1][j-1] => len of longest common substring ending at (i & j) depends on if char matches on ind i-1 & j-1 => which will already be stored bcz we're following tabulation approach:

    - i = 1 -> n
        j = 1 -> m
*/

/* TC : O(n * m), SC : O(n * m) => can be reduced using space optimization to 
O(2*m) */
int LCSubstring(string str1, string str2) {

    int n = str1.length();
    int m = str2.length();

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0)); /* to store the BC : if(ind1 < 0 || ind2 < 0 ) return 0 => whose ans is stored in 0th row and 0th col */

    /* IMP : so just like LCSubsequence DP table : we're storing ans of f(i,j) in dp[i+1][j+1] => bcz of shifting of ind */

    //BC
    for(int i = 0; i < m+1; i++) dp[0][i] = 0;
    for(int i = 0; i < n+1; i++) dp[i][0] = 0;

    int ans = 0;

    for(int i = 1; i < m+1; i++) {
        for(int j = 1; j < n+1; j++) {
            //match
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            //not match
            else{
                dp[i][j] = 0; /* bcz common substring ENDING AT that ind, len of CS is 0*/
            }
        }
    }
    return ans;
}