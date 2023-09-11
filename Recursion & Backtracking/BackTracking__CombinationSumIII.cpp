/* app: {k nos that sums up to n} return all unique combination.
So choosing k nos will be from 1....n, So we need to return all possible 
combinations that sums upto k
A no cannot be used more than once
use no from 1 to 9
=> so k can be from 1 to 9
&& n can be from sum of 1 to 9 */

// solved using BACKTRACKING
class Solution {
private: 
    void f(int i, int k, int tar, vector<int>& arr, vector<int> &t, vector<vector
    <int>>& ans) {
        // bc
        /* if k == 0 & tar == 0 then only we've picked k elems and fulfilled
        the target: so this is one of our ans */
        // moved from 0th to 8th ind
        if(i > 8) {
            if(k == 0 && tar == 0) {
                ans.push_back(t);
            }
            return;
        }


        // sc
        /* pick and notpick approach */
        f(i+1, k, tar, arr, t, ans);

        /* pick: check if can pick or not, & we have pick things k times only,
        and pick it in t vector */
        if(arr[i] <= tar) {
            t.push_back(arr[i]);
            f(i+1, k-1, tar-arr[i], arr, t, ans);
            t.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        for(int i = 1; i <= 9; i++) arr.push_back(i); // chose from 1 to 9
        vector<vector<int>> ans;
        vector<int> t;
        f(0, k, n, arr, t, ans);
        return ans;
    }
};