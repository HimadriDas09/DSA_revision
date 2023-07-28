// LC daily challenge
//V.IMP > for the different type of Recursive Call we do here

/*QUESTION > n len arr > p1 and p2 are competing against each other > 
either of them can choose the starting elem / ending elem of the array > whatever elem they choose gets removed from arr and gets added to their score. 
1st p1 chooses, then next chance is of p2, then of p1 and so on...
score1 : p1 && score2 : p2 
by then end > i.e when arr exhausts if (score1 >= score2) return true else false */

/*APPROACH > try all ways for p1 and p2 to maximize the score of p1 (p1 tries to inc his score and p2 tries to decrease) p1s score
f(i,j,turn) => returns maxScore of p1 for arr[i....j] with last turn = turn
need to keep a track of turn since alternate turn*/

/* 0 -> p1's turn and 1 -> p2's turn
maxScore(i,j,turn) => maximize p1's score in arr[i...j] if lastturn is turn
*/
int maxScore(int i, int j, int turn, vector<int> &nums, vector<vector<vector<int>>> &dp) {
    //bc
    if(i > j) return 0;

    if(dp[i][j][turn] != -1) return dp[i][j][turn];
    if(turn == 0) {
        /* now p1s turn > either pick ith or jth > it'll return maxScore 
        it'll try to maximize p1s score */
        int picki = nums[i] + maxScore(i+1, j, 1, nums, dp);
        int pickj = nums[j] + maxScore(i, j-1, 1, nums, dp);
        return dp[i][j][turn] = max(picki, pickj);
    }
    else {
        /*now p2s turn > either pick ith or jth > it'll try to minimize
        p1s score*/
        int picki = maxScore(i+1, j, 0, nums, dp);
        int pickj = maxScore(i, j-1, 0, nums, dp);
        return dp[i][j][turn] = min(picki, pickj);
    }
}
bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    int totsum = 0;
    for(int i = 0; i < n; i++) totsum += nums[i];
    //memoisation > changing paramter > i,j,turn
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (2, -1)));
    int score1 = maxScore(0,n-1,0,nums, dp);
    int score2 = totsum - score1;
    return score1 >= score2;
}