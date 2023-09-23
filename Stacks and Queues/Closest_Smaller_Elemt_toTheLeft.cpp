#include<bits/stdc++.h>
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<pair<int,int>> st; // elem : ind
    int n = A.size();
    vector<int> ans(n, -1); // initially put -1 everywhere
     
    for(int i = n-1; i >= 0; i--) {
        /* this elem is next smaller to the left of that elem and
        all the other elems in the stack */
        while(!st.empty() && A[i] < st.top().first) {
            ans[st.top().second] = A[i];
            st.pop();            
        }
        st.push({A[i], i});
    }
    return ans;
}
