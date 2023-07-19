#include <bits/stdc++.h> 
string shortestSupersequence(string s1, string s2)
{
	// Write your code here.
	int n = s1.length(), m = s2.length();
	/*tabulation of LCS*/
	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

	//bc : 0th row and 0th col should be 0 done 
	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < m+1; j++) {
			//match
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			//not match
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	/* now traverse from dp[n][m] to 0th row/ 0th col => and whichever characters from both the strings
	that are not part of the LCS add them to a string => that string will be the shortest common 
	supersequence */

	int i = n, j = m;
	string ans = "";
	
	while(i > 0 && j > 0) {
		//match : move diagonally left : common char cutoff
		if(s1[i-1] == s2[j-1]) {
			/* that char from both strings will be cutoff and added once to ans */
			ans += s1[i-1];
			i--,j--;
		}
		//move up : i-1th char cutoff but char of j-1 remains same
		else if(dp[i-1][j] > dp[i][j-1]) {
			ans += s1[i-1];
			i--;
		}
		//move left : char rep by i-1 rem same, but char rep by j-1 is cutoff
		else {
			ans += s2[j-1];
			j--;
		}
	}

	/* now we reached 0th row or 0th col : but still some char of either one string could be 
	remaining to be put to the supersequence : so put them */
	while(i > 0) {
		ans += s1[i-1];
		i--;
	}
	while(j > 0) {
		ans += s2[j-1];
		j--;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}