// LC Hard
// see if we can optimize further using only 1 mp
string minWindow(string s, string t) {
    int n = s.size(), counter_max = 0;
    unordered_map<char,int> mpt; // for t
    for(int i = 0; i < t.size(); i++) {
        counter_max++;
        mpt[t[i]]++;
    }

    unordered_map<char, int> mpw; // cur window
    int l = 0, r = 0, len = 0, counter = 0; /* len == 0 => no such 
    substring that contains all char of t in s > so we return "" */
    string ans = "";

    while(r < n) {
        // include
        mpw[s[r]]++;
        if(mpw[s[r]] <= mpt[s[r]]) counter++; /* only increment counter
        when an elem is reqd is window and it is not present, else counter
        will be incremented more & earlier record string which is not 
        valid */

        // exclude 
        /* things to keep in mind: counter condn and l < r OR l <= r */
        while(l <= r && counter == counter_max) {
            // this is valid window
            if(len == 0 || r-l+1 < len) {
                len = r-l+1;
                ans = s.substr(l, len);
            }
            // else : len is smallest
            // now remove char from window
            mpw[s[l]]--;
            if(mpw[s[l]] < mpt[s[l]]) counter--; /* i.e an elem that should
            be in window is not present so inc more elems */
            l++; 
        }
        r++; // next elem to include
    }
    return (len == 0) ? "" : ans;
}


// according to template



// DON'T PREFER.
// Correct Soln: BUT VERY SPACE HEAVY bcz 2 maps, 1 set and constraints: 10^5

/* since an eligible window can have more than reqd no of elem(i.e eactly that
of t) bcz of way of arrangement of elems in s, we'll calculate len of that window then try to minimize its len */

/* mp2 : contains elem:cnt for ref, mp1: contains exact no of elem in window
and when in window for each char: count >= of count in mp2 then we erase that
elem from set: and when set is empty(i.e all elem of t are atleast in window)
so consider that string */

/* mp1: to track cur elem of cur window
mp2: to track how many elem should there be
st: smt that tell us "every reqd elem is in window: update len and string" 
*/
// #include<bits/stdc++.h>
// class Solution {
// private:
//     void minLenCalc(int l, int r, string &s, int &minlen, string &ans) {
//         if(minlen == 0) {
//             minlen = r-l+1;
//             ans = s.substr(l, minlen);
//         }
//         else {
//             // if cur len is smaller then only update the string, minlen
//             if(r-l+1 < minlen) {
//                 minlen = r-l+1;
//                 ans = s.substr(l, minlen);
//             }
//         }
//         return;
//     }
// public:
//     string minWindow(string s, string t) {
//         int l = 0, r = 0, n = s.size();
//         unordered_map<char,int> mp1, mp2;
//         unordered_set<char> st;
//         int minlen = 0; /* if minlen still remains 0 then return "" */
//         string ans = "";

//         for(auto it : t) {
//             mp2[it]++; // mp2 : elem : cnt
//             st.insert(it); // set : distinct elem
//         }
//         // elem in set: include these in window with cnt of mp2
//         // now iterate s, l to exclude, r to include
//         while(r < n) {
//             // include elem : and inc cnt in mp1
//             if(mp2.count(s[r])) {
//                 // this is reqd in window
//                 mp1[s[r]]++;
//                 if(mp1[s[r]] >= mp2[s[r]]) {
//                     // window contain ATLEAST reqd no of this elem
//                     // so don't include more in window
//                     /* even if we've erased it from set still this executes */
//                     st.erase(s[r]); 
//                 }
//             }

//             // exclude elem to explore more windows: when window is valid 
//             while(st.size() == 0) {
//                 // calculate len 
//                 minLenCalc(l, r, s, minlen, ans);

//                 // now exclude elem using l till window is not valid
//                 /* why would the window not be valid ? : bcz if we encounter 
//                 and elem present in mp2 and we exclude it : but maybe
//                 excluded char was redundant in window : could be > so we check
//                 mp1[char of l]-- => now check is(mp1[char of l] == mp2[char of l]) 
//                 then we shouldn't include an elem in st*/

//                 if(mp2.count(s[l])) {
//                     mp1[s[l]]--; // removed from window
//                     if(mp1[s[l]] >= mp2[s[l]]) {
//                         // more than reqd in window: still a valid window
//                         // no insertion in set: so minlen and string updation
//                         minLenCalc(l, r, s, minlen, ans);
//                         // update before l increases
//                     }
//                     else {
//                         // mp1[s[l]] < mp2[s[l]] : so include more in window
//                         st.insert(s[l]); // s[l] reqd in window
//                     }
//                 }
//                 // l => next elem to remove from window
//                 l++; // even if not in mp2: still to be removed to get min len
//             }
//             // now st.size() != 0 
//             r++; 
//         }
//         return ans;
//     }
// };