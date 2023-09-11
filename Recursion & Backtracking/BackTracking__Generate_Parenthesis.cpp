/* n => n pairs to be formed: so we've 2n options opening and closing inc.
=> if no of opening and closing is same => it is valid solution > NO bcz
)( )( => is not valid 
so rather we keep an op var only && if op == 0 we can't close it */
// BACKTRACKING
class Solution {
private:
    /* cur: is currently formed string by using ( or ) */
    void f(int ind, int op, string &cur, vector<string> &ans) {
        // bc
        if(ind < 0) {
            // if no bracket open then push_back cur to ans
            if(op == 0) ans.push_back(cur);
            return;
        }
        
        // sc
        /* either attach ( or ) bracket, but before appending ), check if we
        can i.e if op == 0 we can't */
        cur += '(';
        f(ind-1, op+1, cur, ans);
        cur.pop_back();

        if(op > 0) {
            // i.e there is a opening open: so we can close it
            cur += ')';
            f(ind-1, op-1, cur, ans);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        f(2*n-1, 0, cur, ans); // opening and closing cnt = 0
        return ans;
    }
};