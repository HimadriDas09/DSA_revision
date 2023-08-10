/* Question > buy and sell, but only k transactions can be made */
#include <bits/stdc++.h> 
/* since we can make at most k transactions > so total buy + sell
is at max 2k => so transNo = 0 -> 2k-1 and in even days we can buy
and in odd days we can sell => based on this we need to maximize the 
profit => so need to try all ways to get profit > so recursion */
int f(int ind, int transNo, int &n, int &k, vector<int> &prices, 
vector<vector<int>> &dp) {
    //bc
    if(ind == n || transNo == 2*k) {
        //now we cannot buy or sell > so we get profit from market is 0
        return 0;
    }
    if(dp[ind][transNo] != -1) return dp[ind][transNo];

    if(transNo % 2 == 0) {
        //we can buy > return max profit
        /* when we buy we go to the nxt, transNo + 1 i.e now we can sell
        but if we don't buy > then don't inc transNo bcz without buying
        we can't sell */
        return dp[ind][transNo] = max(-prices[ind] + f(ind+1, transNo+1, 
        n, k, prices, dp), f(ind+1, transNo, n, k, prices, dp));
    }
    else {
        //we can sell > return max profit
        /* when we sell > we make a profit of +prices[ind] and transNo
        inc by 1 && now becomes even > i.e now we can buy else if
        we don't sell then don't inc the transNo bcz we still have to sell
        before buying */
        return dp[ind][transNo] = max(prices[ind] + f(ind+1, transNo + 1, 
        n, k, prices, dp), f(ind+1, transNo, n, k, prices, dp));
    }
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    /* in memoisation > not necessary to store the bc > so 1 less
    size dp table */
    // vector<vector<int>> dp(n, vector<int> (2*k, -1));
    // return f(0, 0, n, k, prices, dp);

    //tabulation : 
    /* cover all states inc bc needed so [n+1][2*k + 1] */
    vector<vector<int>> dp(n+1, vector<int> (2*k+1, 0));
    //bc covered
    //nested loops in opposite fashion
    for(int ind = n-1; ind >= 0; ind--) {
        for(int transNo = 2*k-1; transNo >= 0; transNo--) {
            if(transNo % 2 == 0) {
                dp[ind][transNo] = max(-prices[ind] + dp[ind+1][transNo+1],
                dp[ind+1][transNo]);
            }
            else {
                dp[ind][transNo] = max(prices[ind] + dp[ind+1][transNo+1],
                dp[ind+1][transNo]);
            }
        }
    }
    return dp[0][0];
}
//SPACE OPTIMIZATION : 
    vector<int> next(2*k+1, 0);
    vector<int> cur(2*k+1, 0);
    //bc covered
    //nested loops in opposite fashion
    for(int ind = n-1; ind >= 0; ind--) {
        for(int transNo = 2*k-1; transNo >= 0; transNo--) {
            if(transNo % 2 == 0) {
                cur[transNo] = max(-prices[ind] + next[transNo+1],
                next[transNo]);
            }
            else {
                cur[transNo] = max(prices[ind] + next[transNo+1],
                next[transNo]);
            }
        }
        /* we're going from ind == n-1 to 0 && we're filling cur
        using next > for the nex itern > cur of prev itern will be next */
        next = cur;
    }
    return next[0];