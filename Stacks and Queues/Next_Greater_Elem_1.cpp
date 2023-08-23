/* most optimal approach: move from right -> left
for each elem > 1st we'll discard all the elems smaller
that it from the stack : if we get a greater elem that will be nge or else if
stack got empty then nge == -1 */

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> st;
    unordered_map<int,int> mp; // map for nums1 to get nge of nums2 in O(1)
    vector<int> ans; // to store nge of nums1 in nums2

    for(int i = nums2.size()-1; i >= 0; i--) {
        /* for each elem i we're checking in the stack: and eliminating 
        smaller elems present in right of elem i */
        while(!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }
        // now either st is empty or st.top() > nums2[i]
        if(st.empty()) mp[nums2[i]] = -1; // nge of nums2[i]
        else {
            mp[nums2[i]] = st.top();
        }
        // push ith elem into the stack
        st.push(nums2[i]);
    }        

    // now for all elem of nums1 get the nge of nums2 
    for(auto it : nums1) {
        ans.push_back(mp[it]);
    }
    return ans;
}


// not most optimzed but O(n2) => using only map for nums1 to reference nge of nums2

// considering no duplicates: for using map
/* App1: for all elem in num1 > find their ind in num2 > and from that ind traverse till u get the next greater elem && push next greater elem in ans 
    TC: 3 nested loops : ~O(n3)

App2: since nums1 is a subset of nums2: if I traverse nums2 and store 
    <elem:ind> in a mp => this also covers nums1. 
    so, storing <elem:ind> if I traverse nums2 from back && for each
    elem[i] if I move from i+1 to n2-1, then I can get the nxt greater elem
    for elem[i] && I am also storing the ind of nums2 for num2
    in map : <elem : <ind, nxtGreater>> 
    TC: 2 nested loops + one itern of num1 : ~O(n2)
*/
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, pair<int,int>> mp;
        int n1 = nums1.size(), n2 = nums2.size();

        for(int i = n2-1; i >= 0; i--) {
            // got the elem & ind
            // if not found greater then put -1: initially do it
            mp[nums2[i]] = {i, -1};

            for(int j = i+1; j < n2; j++) {
                if(nums2[i] < nums2[j]) {
                    mp[nums2[i]] = {i, nums2[j]};
                    break;
                }
            }
        }

        // now traverse nums1 and put req ans in vector
        for(auto it : nums1) {
            if(mp.find(it) != mp.end()) {
                ans.push_back(mp[it].second);
            }
        }
        return ans;
    }
};