#include<bits/stdc++.h>
//ADOBE, MICROSOFT : easy
//make strins 0101010101... or 10101010101....

//solution 2 : easy 
//make both the pattern 0101010 or 10101010 : bcz this is the only possible ans 
/* count operns to do both > and return min */
int makeBeautiful(string str) {
	// Write your code here
	int oneZero = 0, zeroOne = 0;
	for(int i = 0; i < str.size(); i++) {
		//make 1010 > even contains 1 and odd(odd ^ 1 == 1) 0
		if(i % 2 == 0 && str[i] != '1') oneZero++;
		if(i & 1 && str[i] != '0') oneZero++;
		//make 0101 > even contains 0 and odd 1
		if(i % 2 == 0 && str[i] != '0') zeroOne++;
		if(i & 1 && str[i] != '1') zeroOne++;
	}
	return min(zeroOne, oneZero);
}


//solution 1 : Recursive soln : TC : O(2^n), SC : O(n)
/* we need to try all ways to check in which way we need to perform min
operations > Recursion 
f(ind) > min operations to beautify string from ind..n-1 
option: we can actually change the string or keep a track of the prev
elem to know which one between 0 or 1 is in the prev ind 
initially we keep prev = -1 */
//TC : O(2^n) for each ind 2 options , SC : O(n) aux stack space
int f(int ind, int prev, string &str, int &n) {
	//bc
	if(ind == n) return 0;

	//dep on prev value what we'll do
	int cur = str[ind]-48;
	if(prev == -1) {
		//we're at ind 0
		//2 cases : keep value or revert value
		//above can generalize it : convert 1 to 0 and vv but xoring with 1
		return min(f(ind+1, cur, str, n), 1 + f(ind+1, cur^1, str, n));
	}
	else if(prev == 1) {
		//check if 0 > if yes then no operation > else 1 opern
		if(cur == prev^1) {
			return f(ind+1, cur, str, n);
		}
		else {
			//changed cur
			return 1 + f(ind+1, cur^1, str, n);
		}
	}
	else {
		//prev == 0
		//rather generalize it : if (cur = prev^1 i.e opp then do this else do this)
		if(cur == prev^1) {
			//opposite : then no need to change : i.e no operation
			return f(ind+1, cur, str, n);
		}
		else {
			return 1 + f(ind+1, cur^1, str, n);
		}
	}
}
int makeBeautiful(string str) {
	// Write your code here
	int n = str.size();
	return f(0, -1, str, n);
}