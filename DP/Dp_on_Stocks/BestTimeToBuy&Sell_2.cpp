#include<bits/stdc++.h>
/*QUESTION : unlike Buy and Sell 1 : we can (buy,then sell), (buy, then sell), ......multiple times > and buy doing so > we need to maximize the profit*/

/*APPROACH > RECURSION > try all ways to (buy, sell), (buy, sell),.. on diff days
we cannot do (buy, then buy) > so we need to keep a track > so that when we go to nxt ind > I know whether I bought at previously or not 

    f(ind, buy) => starting at index ind, tell me the max profit I can make
    => if I didn't > for ind i > 2 options : buy or not buy
    => if I did buy previously > for ind i > 2 options : sell or not sell
*/


//MEMOISATION CODE : 
long f(int ind, int buy, int &n, long *values, vector<vector<long>> &dp) {
    //bc
    if(ind == n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    long profit = 0;
    if(buy) {
        profit = max(-values[ind] + f(ind+1, 0, n, values, dp),
        f(ind+1, 1, n, values, dp));
    }
    else {
        profit = max(values[ind] + f(ind+1, 1, n, values, dp),
        f(ind+1, 0, n, values, dp));
    }
    return dp[ind][buy] = profit;
}
long getMaximumProfit(long *values, int n)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long> (2, -1));
    return f(0, 1, n, values, dp);//1 bcz initially buy a stock
}