#include <bits/stdc++.h> 
//IMPORTANT : 
/*PROBLEM STATEMENT : 
given n shops > for each shops we have no of working bulbs & total no of bulbs
BULBS = {{works,total}, {works1, total1}, {works2, total2}, ......}

we're given with (extra = smt) bulbs > assign them to stores such that 
avg ratio of working bulbs( = (w1/t1 + w2/t2 + .....)/n ) is maximized
*/

//priority queue used
/*approach > since avg working ratio is max when Nr i.e (sum of each ratio)
is maximum => so how do I know adding a bulb to which shop would maximize
the ratio ? 
=> so adding a bulb to each of the shop => how much would the ratio inc
put that how much in a priority queue => && based on pq.top() we would
add a bulb > since ratio inc now update pq.top() with new how much
avg inc by addition of 1 bulb(i.e delta) > then again based on pq.top() 
add 1 bulb till all extras exhausts 
*/
double maxAverageWorkingRatio(vector<vector<int>>& bulbs, int n, int extra) {
    //pq : {delta, {works, total}}
    priority_queue<pair<double, pair<int,int>>> pq;
    for(int i = 0; i < bulbs.size(); i++) {
        int works = bulbs[i][0];
        int total = bulbs[i][1];

        double delta = (double) (works+1)/(total+1) - (double) (works)/(total);

        pq.push({delta, {works, total}});
        /*firtly based on delta only it arranges each entry*/
    }
    //now assign extra bulbs : based on which one has the max delta
    /* after assigning each bulb : pop out the old entry whose delta
    was max && update the new delta for that entry in pq */
    while(extra > 0) {
        int works = pq.top().second.first;
        int total = pq.top().second.second;
        //inc works & total bcz of extra
        //&& check newDelta > by inc works and total once again
        works++;
        total++;
        double newDelta = (double)(works + 1)/(total + 1) - (double)(works)/(total);
        pq.pop();//pq.top() is poped out > bcz to it 1 extra added
        pq.push({newDelta, {works, total}});
        extra--;
    }
    //by now all extra added to those whose which shows max inc in ratio
    //now sum them up
    double ratio = 0;
    while(!pq.empty()) {

        ratio += (double)(pq.top().second.first )/(pq.top().second.second);
        pq.pop();

    }
    return (double)(ratio/n);
}