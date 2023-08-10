//QUESTION : Buy and Sell infinite times but with COOLDOWN i.e after selling on ith day now can only buy on i+2th day
/* this is buy and sell infinite no of stocks but with cooldown i.e 
after selling a stock on a day > on the next day we cannot buy */
#include<bits/stdc++.h>
int f(int ind, int buy, int &n, vector<int> &prices, vector<vector<int>> 
&dp) {
    //bc : we may not directly fall on nth day : can go beyound that
    //since from n-1th can jump 2steps 
    if(ind >= n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    if(buy == 1) {
        //we can buy
        return dp[ind][buy] = max(-prices[ind] + f(ind+1, 0, n, prices, dp),
        f(ind+1, 1, n, prices, dp));
    }
    else {
        //we can sell
        /* once we sell we can't buy the next day > so we directly go
        to next of next day */
        return dp[ind][buy] = max(prices[ind] + f(ind+2, 1, n, prices, dp),
        f(ind+1, 0, n, prices, dp));
    }
}
int stockProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();
    // vector<vector<int>> dp(n, vector<int> (2, -1));
    // return f(0, 1, n, prices, dp);
        //tabulation : 
    /* cover all the cases > can go from 0 to n+1 at max && buy : 0,1,2
    dp[n+2][3] */
    vector<vector<int>> dp(n+2, vector<int> (3, 0));
    //bc covered : ind == n+1, n && buy == 2
    //nested loops in rev directions : 
    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy < 2; buy++) {
            if(buy == 1) {
                dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],
                dp[ind+1][1]);
            }
            else {
                dp[ind][buy] = max(prices[ind] + dp[ind+2][1],
                dp[ind+1][0]);
            }
        }
    }
    return dp[0][1];
}

//SPACE OPTIMIZATION : 
vector<int> prev2(n+2, 0);
vector<int> prev1(n+2, 0);
vector<int> cur(n+2, 0);
//bc covered : ind == n+1, n && buy == 2
//nested loops in rev directions : 
for(int ind = n-1; ind >= 0; ind--) {
    //can buy
    cur[1] = max(-prices[ind] + prev1[0],
    prev1[1]);

    //can sell
    cur[0] = max(prices[ind] + prev2[1],
    prev1[0]);
    
    /* we're starting from ind == n-1 and going till 0, for the
    next itern > cur will act as prev1 and prev1 will act as prev2 */
    prev2 = prev1;
    prev1 = cur;
}
return prev1[1];