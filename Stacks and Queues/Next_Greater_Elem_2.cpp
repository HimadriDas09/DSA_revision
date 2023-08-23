// same as NGE 1 but we're using circular array

/* since it's circular array: so put duplicate array beside it 
then consider the 2n len array to solve the problem */

/* most optimal approach: move from right(2n-1) -> left(0)
for each elem > 1st we'll discard all the elems smaller
that it from the stack : if we get a greater elem that will be nge or else if
stack got empty then nge == -1 */

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st; // for eliminating smaller elems for future
        int n = nums.size();
        vector<int> ans(n, -1);
        /* even if we traverse the circular 2n sized array : ind == i % n
        would always give us valid i */

        for(int i = 2*n-1; i >= 0; i--) {
            /* in stack: for elem eliminate the smaller elems and 1st 
            encountered greater elem in nge */
            while(!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            // now either st is empty or st.top() > ith elem
            if(st.empty()) {
                if(i < n) ans[i] = -1;
            }
            else {
                if(i < n) ans[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};