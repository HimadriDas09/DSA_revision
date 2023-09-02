// 26th August, 2023 LC challenge
// refered to u tube : for compare function 

#include<bits/stdc++.h>
class Solution {
// private:
/* compare(a,b) is called: i want if a[1] < b[1] : then place a 1st 
compare(a,b) returns true => maintian the order of a[1] then b[1] else 
b[1] then a[1] */
static bool compare(vector<int> &a, vector<int> &b) {
    return a[1] < b[1]; // then a should be before: so return true
}
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), compare);
        int len = 1, prev_ind = 0; // ind 0 is always part of the chain
        for(int ind = 1; ind < n; ind++) {
            if(pairs[prev_ind][1] < pairs[ind][0]) {
                len++;
                prev_ind = ind;
            }
        }
        return len;
    }
};
