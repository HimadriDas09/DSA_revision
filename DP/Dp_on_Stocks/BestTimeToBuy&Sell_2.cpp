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

long spaceOptimization(long *values, int n){

    //2 size 2 vector space optimization : 
    vector<long> ahead(2, 0), cur(2, 0);
    //bc
    ahead[0] = ahead[1] = 0;

    //nested loops : in tab : bottoms up : from bc -> to main problem
    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if(buy) {
                profit = max(-values[ind] + ahead[0], ahead[1]);
            }
            else {
                profit = max(values[ind] + ahead[1], ahead[0]);
            }
            cur[buy] = profit;
        }
        ahead = cur;
    }
    //final ans is in dp[0][1] : at ind 0 we need to buy : give me the max profit that can be earned
    return ahead[1];


    /*****************SAME AS ABOVE**************************************/


    //4 pointer space optimization 
    long aheadNotBuy = 0, aheadBuy = 0;
    long curNotBuy, curBuy;

    for(int ind = n-1; ind >= 0; ind--) {
        //for buy
        curBuy = max(-values[ind] + aheadNotBuy, aheadBuy);

        //for notbuy i.e sell
        curNotBuy = max(values[ind] + aheadBuy, aheadNotBuy);

        //save cur in ahead for nxt itern
        aheadBuy = curBuy, aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    // vector<vector<long>> dp(n, vector<long> (2, -1));
    // return f(0, 1, n, values, dp);//1 bcz initially buy a stock

    //tabulation : 
    vector<vector<long>> dp(n+1, vector<long> (2, 0));
    //bc
    dp[n][0] = dp[n][1] = 0;

    //nested loops : in tab : bottoms up : from bc -> to main problem
    for(int ind = n-1; ind >= 0; ind--) {
        for(int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if(buy) {
                profit = max(-values[ind] + dp[ind+1][0], dp[ind+1][1]);
            }
            else {
                profit = max(values[ind] + dp[ind+1][1], dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    //final ans is in dp[0][1] : at ind 0 we need to buy : give me the max profit that can be earned
    return dp[0][1];
}