//IMPORTANT
/*
    Time Complexity  = O(N)
    Space Complexity = O(N)

    Where N is the length of the string.
*/
/*
    Time Complexity  = O(N * 2)
    Space Complexity = O(N)
   
    Where N is the length of the string
*/
//ap2
string reverseString(string str)
{
    int n = str.length();
	string ans;
	int i = 0;

	while (i < n) 
	{
		int j = i;

		// Skip multiple spaces
		while (j < n && str[j] == ' ') 
		{
			j++;
		}

		string currentWord;

		// Get the current word
		while (j < n && str[j] != ' ') 
		{
			currentWord.push_back(str[j]);
			j++;
		}

		// add current word in the ans with a space
		if (currentWord.length() != 0) 
		{
			ans.insert(0, currentWord + " ");
		}

		i = j + 1;
	}

	if (ans.length() == 0) 
	{
		return ans;
	}

	// remove the last space
	return ans.substr(0, ans.length() - 1);
}

//ap1
#include<bits/stdc++.h>
string reverseString(string &s){
	// Write your code here.	
	stack<string> st;
	int n = s.size();
	int si = -1, ei = -1; //initially
	//now when ei and si is set then only string is pushed to stack
	/*but if at last ind there is a char then we don't set ei and 
	string is not pushed to st*/
	for(int i = 0; i < n; i++) {
		if(si == -1 && s[i] != ' '){
			si = i, ei = i;
		}
		if(i == n-1 && si != -1 && ei != -1) {
			ei = n-1;
			st.push(s.substr(si, ei-si+1));
			break;
		}
		else if(s[i] == ' ' && si != -1) {
			ei = i-1;
			st.push(s.substr(si, ei-si+1));
			si = -1, ei = -1;
		}
	}
	string ans = "";
	while(!st.empty()) {
		ans += st.top();
		st.pop();
		if(!st.empty()) ans += ' ';
	}
	return ans;
}