1)  dp[i][j] => longest Common Substring ENDING  at (i,j) 

    => if we don't hold the above concept then we won't be able to find the LCSubstring

    BUT IN Longest Common Subsequence : 
    dp[i][j] => longest Common Subsequence till ind i,j => does necessarily means that the subsequence is ending at (i,j)
    (bcz in subsequence it's max no of sequential character match)    

2) Whenever you use the concept of LCS to get the len of a string, use the concept of Printing LCS to get the exact string.