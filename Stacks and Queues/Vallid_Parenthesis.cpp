// my approach:
/* APPROACH: keep on pushing into stack and when u encounter a closing bracket
then without pushing it into the stack check if top of the stack contains
matching opening bracket, then pop out opening bracket
    => when string exhausts check if stack is empty or not
*/
#include<bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if(st.empty()) {
                    // closing with no opening before
                    return false;
                }
                // else: check if corresponding opening is in top or not
                if((s[i] == ')' && st.top() == '(') || 
                (s[i] == '}' && st.top() == '{') || 
                (s[i] == ']' && st.top() == '[')) {
                    st.pop(); // opening bracket out
                }
                else {
                    // closing opening doesn't match: push closing
                    st.push(s[i]);
                }
            }
            else{
                // opening encountered
                st.push(s[i]);
            } 
        }
        return st.empty();
    }
};
/*---------------------------------LEETCODE DISCUSSION-----------------------*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  //taking stack for keep tracking the order of the brackets..
        for(auto i:s)  //iterate over each and every elements
        {
            if(i=='(' or i=='{' or i=='[') st.push(i);  //if current element of the string will be opening bracket then we will just simply push it into the stack
            else  //if control comes to else part, it means that current element is a closing bracket, so check two conditions  current element matches with top of the stack and the stack must not be empty...
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();  //if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
        return st.empty();  //at last, it may possible that we left something into the stack unpair so return checking stack is empty or not..
    }
};