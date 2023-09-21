//link: https://www.codingninjas.com/studio/problems/longest-substring-with-at-most-k-distinct-characters_2221410?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

//GOOD question
/* Question: return len of longest substring from the string so that it has atmost k distinct characters */

// approacramesh(most optimal acc to CN) : TC: O(2n) || SC: O(k), k = no of distinct elem in string.

/* L pointer to exclude elem from the subarray && R pointer to include elem into the subarray ==> BUT since duplicates can be present : so st.erase(str[l]); l++ => might not completely remove the elem from the subarray : since condition is valid subarray: contains <= k distinct characters > so with L++ we'll reduce count from map and when (count in mp == 0) ==> we've completely removed elem from the subarray so then we can do st.erase(char at the l value before incrementing) */

/* set : to get no of distinct characters in the subarray */
//EDIT : with the mp.size() we can know no of elem in subarray.

#include<bits/stdc++.h>
int kDistinctChars(int k, string &str)
{
    // Write your code here
    // unordered_set<int> st;
    unordered_map<char,int> mp; // char : count
    int l = 0, r = 0, n = str.size();
    int len = 0; /* it could be possible that 'k' distinct char are not
    present in array */
    while(r < n) {
        mp[str[r]]++;
        // st.insert(str[r]);
        if(mp.size() <= k) {
            len = max(len, r-l+1); 
        /* at most k distinct char: i.e 1 to k could be the size of the set 
        > update len for every elem in subarray */
        }
        while(mp.size() > k) {
            // now st contains k+1 elems
            // more than max elem put in subarray: so remove from left
            len = max(len, r-1-l+1);
            mp[str[l]]--;
            if(mp[str[l]] == 0) {
                // last char from subarray removed
                mp.erase(str[l]);
            }
            l++;
        }
        // st contains <= k elem (with or without above loop), so r++ 
        r++; // r points to nxt elem to be put into the subarray
    }
    return len;
}


