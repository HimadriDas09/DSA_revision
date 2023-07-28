//IMPORTANT : on character matching like Distinct Subsequences
/*Question > s1 = "horse" , s2 = "ros" , find the min no of operations to covert s1 to s2, you can insertion, deletion, replacement*/

/*Appraoch > since can't use greedy so explore all paths > Recursion
    1. expres problem in terms of (i,j) => i rep char of s1, j rep char of s2
        a. f(i,j) > min no of operations to convert s1[0...i] into s2[0...j]

    2. do all stuffs on indices
        a. if char at i & j matches > no need to perform any opernation on those indices and move i.e f(i-1, j-1);
        b. else 
            can perform all the 3 operation > insert, delete, replace
                insert > s1 : "horse", s2 = "ros", i = 4, j = 2, char don't match so 
                    insert "s" on s1, so "s" & "s" matches, j-- but i stays there in case later "e" matches. > 1 + f(i, j-1)
                deletion > above case > delete "e" > i-- but j stays same in case 
                    jth char matches later > 1 + f(i-1, j)
                replacement > above case > since char doesn't match so replace "e" 
                    with "s" > now matches > i--,j-- > 1 + f(i-1, j-1)

    3. base case > one string exhaust and other doesn't > i.e s1 = "horse", s2 = "ros", i == -1 && j == 2, so to convert s1 to s2 > req j+1 insertions 
    sim, j == -1 && i == 3, so to convert s1 to s2 > req i+1 deletions
*/
//memoisation > 1 based ind for tabulation
int f(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
    //bc > when i < 0 & j isn't or when j < 0 & i isn't
    if(i == 0) return j;
    if(j == 0) return i;

    if(dp[i][j] != -1) return dp[i][j];
    //sc
    //char matches
    if(word1[i-1] == word2[j-1]) return dp[i][j] = f(i-1, j-1, word1, word2, dp);

    //else > 3 options
    return dp[i][j] = 1 + min(f(i, j-1, word1, word2, dp), 
    min(f(i-1, j, word1, word2, dp),f(i-1, j-1, word1, word2, dp)));
}
//tabulation
int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    //memoisation > dp[n][m]
    // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // return f(n, m, str1, str2, dp);

    //tabulation
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    //bc
    //for any i where j == 0, put i
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    //for any j, where i == 0, put j
    for(int j = 0; j <= m; j++) dp[0][j] = j;
    
    //bottom up app > nested loop > i = 1 -> n && j = 1 -> m
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            //copy the rec
            //char matches
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];

            //else > 3 options
            else{
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
    }
    //final ans > dp[n][m] > min no of oper to convert str1 [0..n] to str2[0...m]
    return dp[n][m];
}
//space opt
int editDistance(string str1, string str2)
{
    //write you code here
    int n = str1.size();
    int m = str2.size();
    //memoisation > dp[n][m]
    // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    // return f(n, m, str1, str2, dp);

    //tabulation
    // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    vector<int> prev(m+1, 0);
    vector<int> cur(m+1, 0);
    //bc
    //for any i where j == 0, put i
    // for(int i = 0; i <= n; i++) dp[i][0] = i;
    //for any j, where i == 0, put j
    for(int j = 0; j <= m; j++) prev[j] = j;
    
    //bottom up app > nested loop > i = 1 -> n && j = 1 -> m
    for(int i = 1; i <= n; i++) {
        cur[0] = i; 
        for(int j = 1; j <= m; j++) {
            //copy the rec
            //char matches
            if(str1[i-1] == str2[j-1]) cur[j] = prev[j-1];

            //else > 3 options
            else{
                cur[j] = 1 + min(cur[j-1], min(prev[j], prev[j-1]));
            }
        }
        prev = cur;
    }
    //final ans > dp[n][m] > min no of oper to convert str1 [0..n] to str2[0...m]
    // return dp[n][m];
    return cur[m];
}