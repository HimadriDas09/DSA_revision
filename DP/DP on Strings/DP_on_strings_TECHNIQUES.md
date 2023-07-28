1)  dp[i][j] => longest Common Substring ENDING  at (i,j) 

    => if we don't hold the above concept then we won't be able to find the LCSubstring

    BUT IN Longest Common Subsequence : 
    dp[i][j] => longest Common Subsequence till ind i,j => does necessarily means that the subsequence is ending at (i,j)
    (bcz in subsequence it's max no of sequential character match)    

2) Whenever you use the concept of LCS to get the len of a string, use the concept of Printing LCS to get the exact string.

3) BC for 2 string comparison > 
    i) when only s1 exhausts
    ii) when only s2 exhausts

4) memoisation 0 based conversion to memoisation 1 based ind for tabulation 
    - increase the size of dp[n][m] to dp[n+1][m+1]
    - initial rec call is on f(n,m) instead of f(n-1, m-1)
    - convert all the i < 0 to i == 0, j >= 0 to j > 0
    - convert all the character comparison from if(s1[i] == s2[j]) to
        if(s1[i-1] == s2[j-1])
    
5) for all the non standard questions on DP on strings like
    - shortest Common Supersequence(
        Q : 2 strings are given, find the shortest string from which these 2 strings 
            can be derived.
            eg : s1 : "brute", s2 : "groot"
            ans : "bgruoote" > lcs : "rt"

        Approach : 
        ans => len : (s1 - lcs) + (s2 - lcs) + lcs
        so iterating the LCS tabulation table to find out which out of sequence in which characters from either of s1 and s2 were not included in LCS
    )

    - distinct subsequence(
        Q: s1 = "babgbag", s2 = "bag"
        how many times s2 can be extracted out of s1

        ans : 5
        bcz : ba*g***, ba****g, b****ag, **b**ag, ****bag

        Approach : BASED ON CHAR MATCHING
        match & notmatch => even after match > we can still choose
        whether to pick this char OR i'll not pick it and look for this char in rem part of the string
    )

    - Edit Distance(
        Q : s1 = "horse" , s2 = "ros" , find the min no of operations to covert s1  to s2, you can insertion, deletion, replacement

        ans : 3 (1 to delete "e", 1 to delete "r", 1 to replace "h" with "r")
            So without trying all ways we cannot figure the ans out.

        APPROACH : CHAR MATCHING
        if char matches then no need to perform any operation && both strings are reduced by 1
        else we perform all 3 operations.
        BC : acc to if s1 exhausts then do this and if s2 exhaust then return this
    )

    - WildCard Matching(
        Q: a pattern string and a word string is there 
            both contain lower case but pattern also contains ? -> rep 1 char
            and * -> rep >= 0 len char/sequence
            return true/ false based on if word matches pattern.
        ans : 
            eg : p = "ab?cd" && t = "abecd" then true
            eg : p = "ab?cd" && t = "abced" then false
                bcz in place of ?, c is ok but rest is not following pattern
            
            eg : p = "ab*cd" && t = "abcd" then true 
                bcz * matches with 0 len string
            eg : p = "ab*ed" && t = "abccd" then false
                bcz "ab" "ab" matches fine, "d" matches fine, but even if "*" rep "cc" in text then "e" cannot be matched to anything, or if "*" rep "c", then other "c" is left. So doesn't match
            
            eg : p = "ab*cd" && t = "abdefcd", * rep def else all char matches so ans is true

        APPROACH : CHAR MATCHING
            BC : same technique
            if char matches > fine and if ? appear in pattern then also fine
                both cases : both strings reduces by 1 len i.e return f(i-1,j-1);
            else if (* appears in pattern) > * could rep 0/1/2/3..... len sequence
                so RC : return f(i-1,j) | f(i, j-1);
            else i.e char don't match:
                return false;

    )