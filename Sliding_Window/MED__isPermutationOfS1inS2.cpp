/* app: if a permutation of smallStr occur in bigStr.
The permutation len is same as smallStr => explore all constant len window.
exact char with cnt should occur in window. Maintian a cnt that will tell exact 
char with cnt is present or not. if yes return true.
maintain slen, winlen, counter, wincnt */
class Solution {
public:
// TC: O(n1 + n2), SC: O(n1+n2)
// if s2 contains permutations of s1
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        /* for s2 to contain permutations of s1, it has to be atleast the len of 
        s1 */
        if(n2 < n1) return false;
        unordered_map<char,int> mp1;
        int winLen = 0;
        int winCnt = 0; /* winCnt == n1, means our current window contains 
        everything for cur window substring to be a permutation, 
        we need to maintain a mp for cur window, to know what char it contains
        based on that we inc winCnt */
        for(int i = 0; i < n1; i++) mp1[s1[i]]++;

        /* for every winLen == n1 sized window, check if winCnt == n1, 
        if not => explore the next window by inserting and removing one */
        int l = 0, r = 0;
        unordered_map<char,int> mp2;
        while(r < n2) {
            // INCLUDE 
            mp2[s2[r]]++;
            if(mp1.count(s2[r]) && mp2[s2[r]] <= mp1[s2[r]]) winCnt++;
            winLen++;

            if(winLen == n1 && winCnt == n1) {
                return true; /* winLen correct and cur window contains exact char
                with cnt as in s1 */
            }
            else if(winLen == n1) {
                // EXCLUDE
                /* winCnt < n1 : so explore other window: exclude char at l */
                mp2[s2[l]]--;
                if(mp1.count(s2[l]) && mp2[s2[l]] < mp1[s2[l]]) {
                    /* if currently excluded from window, it's cnt got less than
                    it's supposed to be: then dec counter */
                    winCnt--;
                }
                if(mp2[s2[l]] == 0) mp2.erase(s2[l]);
                l++; // next to exclude
                winLen--;
            }
            r++; // next to include
        }
        return false; 
    }
};