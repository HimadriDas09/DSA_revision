/*QUES: Find the min len substring containing all the unique characters of the string 

app: set contains all the unique char of the string
now keep on inc elem in window till our counter(which only counts for unique elem == st.size()) > while(till cur window is valid i.e counter == st.size()) {
    update len
    exclude elem; // to explore inner substring

    if(that elem was the last of its type) counter--;

    // now out of loop we'll include more characters
}
*/

class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int n = str.size();
        unordered_set<char> st;
        for(auto it : str) {
            st.insert(it);
        }
        
        int l = 0, r = 0; 
        int len = n; // maxLen that contains all the distinct character of the string 
        vector<int> mp(128, 0); // char : cnt in cur window
        int counter = 0; /* counter to know if our cur window
        have all the unique characters of str or not */
        
        while(r < n) {
            // include
            mp[str[r]]++;
            if(mp[str[r]] == 1) counter++;
            
            // exclude
            while(l <= r && counter == st.size()) {
                /* so cur window contains all the unique elem of the string: so reduce the len while maintaining 
                all the unique char to get the min len substring */
                len = min(len, r-l+1);
                
                mp[str[l]]--; // removed from cur window
                if(mp[str[l]] == 0) counter--; /* completely removed from the window: so have to take it again */
                l++; // elem to remove 
            }
            r++; // elem to take in window
        }
        return len;
    }
};