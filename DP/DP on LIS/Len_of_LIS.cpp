#include<bits/stdc++.h>
//METHOD 2 : directly creating a dp table > IMP if you want to print the LIS
/* based on dp[i] => contain LIS ending at ind i */
vector<int> dp(n, 1);
int maxi = 1;
for(int ind = 0; ind < n; ind++) {
    for(int prev = 0; prev < ind; prev++) {
        if(arr[prev] < arr[ind]) {
            dp[ind] = max(1 + dp[prev], dp[ind]);
        }
    }
    maxi = max(dp[ind], maxi);
}
return maxi;


//METHOD 1 
/* Using Recursion > keep a track of prev_ind whose elem you've choosen
to check if choosing cur elem would maintain the LIS 
> f(ind, prev_ind) > give me the LIS from ind...n-1 if prev_ind elem is
choosen previously */
/* the changing para has to be in form of ind or some definite val
so that we can rep that in dp table : so we choose prev_ind rather
than prev_val */
int f(int ind, int prev_ind, int* arr, int &n, vector<vector<int>> &dp) {
    //bc
    if(ind == n) return 0;

    if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
    //not take
    int nottake = f(ind+1, prev_ind, arr, n, dp);
    //take
    int take = 0;
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
        /* above cnd satisfy then we can definitely take it */
        take = 1 + f(ind+1, ind, arr, n, dp);
    }
    return dp[ind][prev_ind+1] = max(take, nottake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    /* memoisation : changing para > ind : 0...n-1 && prev_ind : 
    -1....n-1 but in dp table there isn't any -1 ind > 
    so calculate the ans of ind == -1 but store it in ind == 0 and 
    look for ans of ind in dp[ind+1] only */
    // vector<vector<int>> dp(n, vector<int> (n+1, -1));
    // return f(0, -1, arr, n, dp);

    /* tabulation: consider all cases inc bc for dp table creation
    ind: 0....n && prev_ind: 0....n > dp[n+1][n+1] */
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    //bc covered
    /* nested loops in opp fashion > ind: n-1....0 && prev_ind: n-1...-1 */
    for(int ind = n-1; ind >= 0; ind--) {
        for(int prev_ind = ind-1; prev_ind >= -1; prev_ind--) {
            int nottake = dp[ind+1][prev_ind+1]; //bcz f(ind+1, prev_ind) stored in dp[ind+1][prev_ind+1]
            //take
            int take = 0;
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
                /* above cnd satisfy then we can definitely take it */
                take = 1 + dp[ind+1][ind+1];// f(ind+1, ind) stored in dp[ind+1][ind+1]
            }
            dp[ind][prev_ind+1] = max(take, nottake);
        }
    }
    return dp[0][-1+1]; //f(0,-1) stored in dp[0][-1+1]
}