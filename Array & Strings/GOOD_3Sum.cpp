/* Q. ALl unique set of triplets whose sum is 0 */
// app1: brute force : O(n3)

/*app2: use hashing to get the 3rd no && using nested loops explore all
the 2 numbers : But don't use the same elem twice, so in a map, put
only the between elems of the 2 pointers */

#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    // must have unique triplets
    set<vector<int>> st;
    unordered_map<int,int> mp; // elem : ind
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            /* now look for -(arr[i] + arr[j]) to get sum == 0 */
            /* even if multiple rems are present in arr, with constant
            arr[i], arr[j], it is useless to get duplicate */
            int rem = -(arr[i] + arr[j]);
            if(mp.count(rem)) {
                vector<int> t = {arr[i], arr[j], arr[mp[rem]]};
                sort(t.begin(), t.end());
                st.insert(t);
            }
            /* rem found or not found: insert arr[j] in mp */
            mp[arr[j]] = j;
        }
        mp.clear(); // emtpy set for next itern
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

/*app3: most optimal > in sorted array fix one pointer and use 2 sum*/
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> st; // contains unique triplets
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++) {
        // 2 pointers are l,r at 0 and i-1
        /* condn: l >= 0 && r < n && l < r */
        int l = 0, r = i-1;
        int sum;
        while(l >= 0 && r < n && l < r) {
            sum = nums[i] + nums[l] + nums[r];

            if(sum > 0) r--;
            else if(sum < 0) l++;
            if(sum == 0) {
                // is valid set
                vector<int> temp = {nums[l], nums[r], nums[i]};
                st.insert(temp);
                r--, l++;
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end()); /* storing the set
    in vector */
    return ans;
}
