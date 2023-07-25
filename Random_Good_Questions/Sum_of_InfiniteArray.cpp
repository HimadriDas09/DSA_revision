#include<bits/stdc++.h>

//EASY : 

/*PROBLEM STATEMENT => eg : arr [1,2,3]
say B = [1,2,3,1,2,3, .........1,2,3,.....]
B is infinite repeation of arr
given queries = {{l,r}, {l2,r2}, {l3,r3}, .....}
so each of the queries > from ind l to r in B find sum and store in vector
*/

//TC : O(q) && SC : O(n) 
    //but CN shows further TC optimization can be performed
long long mod = 1e9 + 7;
/*NOTE : modulo works on int, long, long long && not on double */
vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here
    // int n = arr.size();
    vector<int> ans;
    long long Prefix_sum = 0;
    map<int, long long> Prefix_mp; //ind : sum
    for(int i = 0; i < n; i++) {
        Prefix_sum += arr[i];
        Prefix_mp[i] = Prefix_sum;
    }
    //q queries are given > for each find sum and push in vector
    for(int i = 0; i < q; i++) {
        //l and r are 1 based
        long long l = queries[i][0];
        long long r = queries[i][1];
        long long sum = 0;
        /*if we remove the while loop > can also do it using prefix
        sum concept*/
        /*now for each l & r > determine how many complete arr it has
        crossed by l/n && in mid of how many using l % r */
        long long comp = 0;
        long long rem = 0;

        comp = (l-1) / n;
        rem = (l-1) % n;
        long long prefixSumBeforeL = (comp * Prefix_mp[n-1]);
        if(rem != 0) {
            prefixSumBeforeL += (Prefix_mp[rem-1]); //sum from 0 to some ind
        }
        //now do same for r
        comp = r / n;
        rem = r % n;
        long long prefixSumtillR = (comp * Prefix_mp[n-1]);
        if(rem != 0) {
            prefixSumtillR += (Prefix_mp[rem-1]);
        }
        
        //ans = prefix till R - prefix before L 
        sum = prefixSumtillR - prefixSumBeforeL;    
        ans.push_back(sum % mod);
    }
    return ans;
}
    //from l go to r && keep summing up values
    // (l % n) - 1 gives ind no && if (l % n) == 0 then ind == n-1
    // while(l <= r) {
    //     long long ind = (l % n);
    //     if(ind == 0) {
    //         //ind == n-1
    //         ind = n-1;
    //     }
    //     else {
    //         ind--;
    //     }
    //     sum += arr[ind];
    //     l++;
    // }