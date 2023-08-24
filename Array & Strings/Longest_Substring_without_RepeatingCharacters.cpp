//APPRAOCH 1 : Sliding Window + set => if repeated character appear then we start removing characters from substring or set from the beginning so as to maintain a substring.
// TC: O(2n) && SC: O(k) k = no of unique char in the string.
#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int L = 0, R = 0, n = s.size();
        if(n == 0) return 0; // s len == 0
        int ans = 1;
        while(R < n) {
            if(!st.contains(s[R])) {
                // s[R] not in st: so include it
                st.insert(s[R]);
                ans = max(ans, R-L+1);
                R++;
            }
            else {
                // s[R] is in st: so eliminate an elem from set
                st.erase(s[L]);
                L++;
            }
        }
        return ans;
    }
};