// (most optimal) TC : O(n) && SC : O(n) 
#include<bits/stdc++.h>
bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char> st;
    
    for(int i = 0; i < s.length(); i++) {
        /*if its an opening bracket then we push it to stack*/
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else {
            /*it a closing bracket :
            - now if st is still empty() i.e beg of s is closing br
            then return false => we cannot balance it out*/
            if (st.empty())
              return false;
    
            /*so there is smt in stack : so with our 1st encountered
            closing bracket : if there is a matching open bracket
            then fine else unbalanced*/
            int top = st.top();
            /*NOTE : st.top() returns a reference to top elem => so for 
            empty stack => it'll give reference ERROR*/
            st.pop();
            
            if ((s[i] == '}' && top == '{') ||  (s[i] == ']' && top == '[') ||
            (s[i] == ')' && top == '(') ) continue;
            else return false;
        }
    }
    if(st.empty()) return true;
    return false;
}