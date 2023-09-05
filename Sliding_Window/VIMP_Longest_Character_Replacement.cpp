/*Based on the maxfreq character in cur window && substracting it from the cur window len we can know how many minority characters are there who are different which are the min no of character are be replaced using k in cur subarray : So we traverse the mp to find the maxfreq character in O(26)*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp; // char:cnt
        int l = 0, r = 0, len = 0, n = s.size();

        while(r < n) {
            // include in window
            mp[s[r]]++;
            
            // check if valid window: update the len
            /* cur window len - max freq in window = rest of char which we can
            make same as the max freq one if it's <= k */
            int maxfreq = 0;
            for(auto it: mp) {
                if(it.second > maxfreq) maxfreq = it.second;
            }
            if(r-l+1 - maxfreq <= k) {
                // unequals can be equalized using k : so update len
                len = max(len, r-l+1);
            }
            else {
                while(r-l+1 - maxfreq > k) {
                    mp[s[l]]--;
                    l++;
                    // cnt the maxfreq
                    maxfreq = 0;
                    for(auto it:mp) {
                        if(it.second > maxfreq) maxfreq = it.second;
                    }
                }
            } 
            r++; // the next elem to inc in window
        }       
        return len; 
    }
};