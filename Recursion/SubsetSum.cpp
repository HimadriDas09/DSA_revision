#include <bits/stdc++.h> 
/*approach => explore all possible subsets => how ? 
recursion => take and nottake app
&& when we reach bc => then push it to a vector
f(i-1) => returns vector having all subset sums from 0...i-1
*/

//TC : O(2^n), SC : O(2^n) => i.e explore all subsets
void helper(int ind, vector<int> &ans, int sum, vector<int> &arr) {
    if(ind < 0) {
        ans.push_back(sum);
        return;
    }

    //nottake
    helper(ind-1, ans, sum, arr);
    //take
    helper(ind-1, ans, sum+arr[ind], arr);
    return;
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int n = num.size();
    vector<int> ans;
    helper(n-1, ans, 0, num);
    sort(ans.begin(), ans.end());
    return ans;
}