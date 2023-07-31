int n = prices.size();
    int mini = prices[0], profit = 0;//initial profit is 0
    /*i.e selling stock on ith day, for that keep a track of left of 
    i for min cost price => && update the profit for each day
    i.e I'm selling it on this day, and previously I bought it on
    a day such that diff betn SP & CP is max */
    for(int i = 1; i < n; i++) {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        //update mini for nxt iterns
        mini = min(mini, prices[i]);
    }
    return profit;