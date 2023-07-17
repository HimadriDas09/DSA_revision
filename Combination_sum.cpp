#include<bits/stdc++.h>

/* PROBLEM STATEMENT : arr : [1,2,3], target = 5 
so return all the combinations (or subsets) that sums upto target
and each combination should be in inc order (=> that why we 1st sorted arr)
OUTPUT : [
    [1,1,1,1,1],
    [1,1,1,2],
    [1,1,3],
    [1,2,2],
    [2,3]
]*/

void helper(int ind, int tar, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int &n)
{
    //bc
    if(tar == 0) {
        ans.push_back(temp);
        return;
    }
    if(ind == n) return;

    //sc
    //not pick
    helper(ind+1, tar, arr, temp, ans, n);

    //pick 
    if(arr[ind] <= tar) {
        temp.push_back(arr[ind]);
        helper(ind, tar-arr[ind], arr, temp, ans, n);
        /*now that if this lead to combination vector, its pushed to ans
        so lets free up space in temp*/
        temp.pop_back();
    }

    return;
}
vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    // Write your code here.
    sort(ARR.begin(), ARR.end());
    int n = ARR.size();
    vector<vector<int>> ans;
    vector<int> temp;

    helper(0, B, ARR, temp, ans, n);

    return ans;
}