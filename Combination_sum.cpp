#include<bits/stdc++.h>
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