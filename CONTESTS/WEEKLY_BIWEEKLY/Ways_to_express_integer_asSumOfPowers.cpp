//biweekly 109

/*QUESTION => 
    n & x is given : express n as sum of unique (elements)^x, return in how many ways can we do that : 
    eg : n = 10, x = 2 
        ans = 1 bcz 10 = 1^2 + 3^2 

    eg : n = 4, x = 1
        ans = 2 bcz 4 = 4^1 && 4 = 3^1 + 1^1 


    approach => what elements could be there in the representation of n => 
    at max an elem such that elem^x <= n 
        so elem > 1 to elem such that elem^x <= n

        put all these elems in a vector
        then on this vector apply > count subsets such that subset sum == n
*/


/*n => to check if sum of elem^x equals to n or not*/
//helper(i) returns no of ways to rep n as sum of elem^x from [0...i]
long long helper(long long i, long long sum, int &n, vector<long long> &arr, vector<vector<long long>> &dp) {
    //bc > if(sum == n) && if(i < 0)
    if(sum == n) return 1;
    if(i < 0) return 0;

    if(dp[i][sum] != -1) return dp[i][sum];
    //sc
    //notpick
    long long notpick = helper(i-1, sum, n, arr, dp) % mod;

    //pick
    long long pick = 0;
    //NOTE : not even picking if it exceeds so won't exceed
    if(sum + arr[i] <= n) {
        pick = helper(i-1, sum + arr[i], n, arr, dp) % mod;
    }

    //since no of ways if we pick & no of ways if we dont pick
    //so we explored all > so ans = pick + notpick
    return dp[i][sum] = (pick + notpick) % mod;
}
int numberOfWays(int n, int x) {
    /* so to rep n as sum of elem whose pow is x 
    => determine from 1 till what elem can we pick so that their
    sum is <= n */        
    
    vector<long long> arr;
    for(long long i = 1; pow(i,x) <= n; i++) {
        arr.push_back(pow(i,x));
        /*now from this arr only pick or notpick to det no of ways*/
    }
    long long len = arr.size();
    //memoisation : 
    /* dp[i][j] > form ind i...0 no of ways to rep n if j == already 
    acquired sum */
    vector<vector<long long>> dp(len, vector<long long> (n+1, -1));

    long long count = helper(len-1, 0, n, arr, dp);

    return count % mod;
}