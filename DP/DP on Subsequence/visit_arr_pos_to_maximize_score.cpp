//biweekly contest 109

/* question is you're at 0th ind, you can move from 0th ind to any index or 
pick up elem to maximize score : i to j => score += nums[j], initial score is nums[i] but if i & j are opp parity then along with summation, x is subtracted from sum, return the max sum possible */

long long helper(int i, int prevPar, vector<int> &nums, int &x, int &n, vector<vector<long long>> &dp) {
        //bc
        if(i > n-1) {
            return 0;
        }
        
        if(dp[i][prevPar] != -1) {
            return dp[i][prevPar];
        }
        //sc
        //not pick
        long long notpick = helper(i+1, prevPar, nums, x, n, dp);
        
        //pick
        long long sum = 0;
         sum += nums[i];
        
        int curPar = nums[i] % 2;
        
        if(prevPar != curPar) {
            sum -= x;
        }
        
        long long pick = sum + helper(i+1, curPar, nums, x, n, dp);
        
        return dp[i][prevPar] = max(pick, notpick);
    }
long long maxScore(vector<int>& nums, int x) {
    int n = nums.size();
    
    //memoisation
    vector<vector<long long>> dp(n, vector<long long> (2, -1));
    //pick nums[0] in all cases
    long long sum = nums[0];
    int prevPar = nums[0] % 2;
    long long ans = sum + helper(1, prevPar, nums, x, n, dp);
    return ans;
}