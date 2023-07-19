string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	
	/* so from the dp table of Longest Common Subsequence : based
	which char matches from dp[n][m] till 0th row/0th col we can find 
	the LCS */
	/*NOTE : if dp[i][j] == 3 then it does mean that longest common 
	subsequence ends at (i,j) => BUT IN CASE OF LCSubstring it does*/

	vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

	//all elem 0 => so bc done 

	for(int i = 1; i < n+1; i++) {
		for(int j = 1; j < m+1; j++) {
			//match
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			//not match
			else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	//now traverse the tabulation table

	int len = dp[n][m];//len of longest common subsequence
	string ans = "";
	for(int i = 0; i < len; i++) ans += '*';
	int index = len-1;

	int i = n, j = m;

	while(i > 0 && j > 0) {
		//match
		if(s1[i-1] == s2[j-1]) {
			//so it came to dp[i][j] from dp[i-1][j-1] so go there
			ans[index] = s1[i-1];
			index--;
			i--,j--;
		}
		/*it came to dp[i][j] from dp[i-1][j] or dp[i][j-1] dep on 
		which one holds max ans */
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}

	return ans;
}