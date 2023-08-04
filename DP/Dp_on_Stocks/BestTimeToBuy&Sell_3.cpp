#include<bits/stdc++.h>
/*QUESTION : same as buy nd sell 2 : i.e we need to buy nd sell multiple times to maximize our profit 
but here > we can only do 2 transactions : so additionally on the buy nd sell 2 we need to keep a 3rd variable cnt(so that we only do transactions twice) */


/*since we cannot do more than 2 transactions so max profit within
integer range*/
/*so we'll maitain a cnt > and when we sell for the 1st time we'll do
cnt + 1 => we only do transaction when we buy nd sell && not when we only buy it => we're supposed to do at most 2 transanctions */


//MEMOISATION CODE 
int f(int ind, int buy, int cnt, int &n, vector<int> &prices, vector<vector<vector<int>>> &dp) {
    //bc
    if(cnt == 2 || ind == n) return 0;

    if(dp[ind][buy][cnt] != -1) return dp[ind][buy][cnt];

    int profit = 0;
    if(buy) {
        //buy, not buy
        profit = max(-prices[ind] + f(ind+1, 0, cnt, n, prices, dp),
        f(ind+1, 1, cnt, n, prices, dp));
    }
    else {
        //sell, not sell
        profit = max(prices[ind] + f(ind+1, 1, cnt+1, n, prices, dp),
        f(ind+1, 0, cnt, n, prices, dp));
    }
    return dp[ind][buy][cnt] = profit;
}
int maxProfit(vector<int>& prices)
{
    // Write your code here.
    int n = prices.size();
    //memoisation : changing para : ind,buy,cnt
    /* ind : 0....n-1, buy : 0,1 , cnt : 0,1 => dp[n][2][2] */
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (2, -1)));
    return f(0, 1, 0, n, prices, dp);
}