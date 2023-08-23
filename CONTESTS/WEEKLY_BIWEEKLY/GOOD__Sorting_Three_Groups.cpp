//BIWEEKLY 111 : MEDIUM(solved) (to understand the question) solun :  EASY

/* QUESTION : 3 grps are there 1/2/3 : nums[i] contain 1/2/3 > i is present in grp nums[i], elems of each of the grps are sorted and appended to a vector res in the order grp1 then grp2 then grp3 > if after appending of each of the grp after res in the order 1,2,3 , if res is a non dec array then nums[] is said to be beautiful,

You're allowed to perform the operation any no of times :
operation : pick a no x and change it's grp OR rather Change num[x] to any value 1/2/3
*/

/* how did I approach the solution : 
    What am I appending in res ? : (sorted values present in grp 1) then (of grp2) then (of grp3). 
    So, I am appending indices to res ? > how do I make the whole thing in non dec order ? > indices of the whole array is already in non dec order and there is no other way to do it. 
    since I need to append res.(...elem of grp...)(...grp2...)(...grp3...)
    either of the grps can be empty : i.e after conversion maybe only 1 is present in array or 1,2 is present or smth else...
    So we need to find min no of operations to convert the arr into an increasing array
    say : 2,2,2,2,2,2,3,3 OR 1,1,1,2,2,2,3,3 OR 1,1,1,1,1,1,1, OR 3,3,3,3,3,3
    so whichway way supports doing min no of operation
    SO RECURSION : to explore all ways
    NOTE : we're not changing the array rather only finding the min no of operations by keeping a track of prev.
    > for each elem : 3 options : 1/2/3 > && if elem stays same : i.e 0 operation and if we change it then 1 operation
    SO how do I explore the possibilities for each index : if I move from n-1....to..0 I need to be aware of what is in (i+1)th ind to change or keep same the ith ind elem > initially 3 options at n-1th ind : (1,2,3) (bcz even if we keep it 1 then there is a possibility that converting the whole nums in min operations could give us 1,1,1,1,1,1,1...) 
    for each ind we go from 1 to 3 but if i+1th ind is 2 then i can only go from 1 to 2 > so for each ind possibility is (1 to next ind value , value being changing or keep their grps i.e prev in this case)
    
    && in bc : 
*/

#include<bits/stdc++.h>
class Solution {
private:
// f(ind, prev) : from 0...ind min no of operations to convert nums into a non dec array if prev elem or ind+1 th elem is prev
    int f(int ind, int prev, vector<int> &nums, vector<vector<int>> &dp) {
        //bc
        if(ind < 0) return 0;
        
        if(dp[ind][prev] != -1) return dp[ind][prev];
        int cnt = INT_MAX; // so not exceed int limit
        for(int grp = 1; grp <= prev; grp++) {
            if(grp == nums[ind]) {
                //grp stays same
                cnt = min(cnt, f(ind-1, grp, nums, dp));
            }
            else {
                //convert to some other grp : 1 opern
                cnt = min(cnt, 1 + f(ind-1, grp, nums, dp));
            }
        }
        return dp[ind][prev] = cnt;
    }
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        /* memoisation: changing para : ind : 0...n-1 && prev : 1...3 */
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return f(n-1, 3, nums, dp);// prev == 3 : so that for last no we explore all 3 grps
    }
};