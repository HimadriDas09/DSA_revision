#include<iostream>
#include<vector>
using namespace std;

// lc similar question link: https://leetcode.com/problems/perfect-squares/description/

//Count the min no of squares that add upto 'n'

/* Approach: Standard Recursion Approach: create an array that contain square of no from 1 till the square value is <= n > then Recursion on the array to find out all possible ways such (subset sum == target) > for each no added find the min count */

/* int f(ind, target) > give me min no of values whose addition gives us target */

/* then to this apply : shifting of ind && tabulation and space optimization */
int f(int ind, int tar, vector<int> &arr, vector<vector<int>> &dp) {
    //bc
    if(tar == 0) return 0;
    if(ind < 0) return 1e9; /* above not true but this is true : so min no of ways is +ve infinity */

    if(dp[ind][tar] != -1) return dp[ind][tar];
    //notpick
    int notpick = f(ind-1, tar, arr, dp);
    //pick : check if can pick
    int pick = 1e9;
    if(arr[ind] <= tar) {
        pick = 1 + f(ind-1, tar-arr[ind], arr, dp);
    }
    //can happen that both return 1e9 : so impossible to find no of squares that add up to n
    return dp[ind][tar] = min(pick, notpick);
}

int minSquares(int n) {
    vector<int> arr;
    for(int i = 1; i*i <= n; i++) {
        arr.push_back(i*i);
    }
    int size = arr.size();
    //memoisation : f(ind, tar) : ind : n-1...0 && tar : 1...n
    vector<vector<int>> dp(size, vector<int> (n+1, -1));
    //start from ind 0, n is the target
    int ans = f(size-1, n, arr, dp);
    return ans == 1e9 ? -1 : ans;
}

int main()
{
    int n;
    cout << "enter value of n : " << endl;
    cin >> n;
    if(n <= 0) {
        cout << "positive squares can not add upto n" << endl;
    }
    else {
    cout << "ans : " << minSquares(n) << endl;
    }
    return 0;
}