//Biweekly 111 
/* QUESTION (MEDIUM)(solved): You are given two 0-indexed strings str1 and str2.

In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.

Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.
*/

/* How did I appraoch the question : 
    SO since we're supposed to inc a character in cycle order : in case of Str1 only 

    But we need to find : if by applying operations on str1 , can Str2 be a subset of str1 or not ? 
    i.e making changes in str1 to find if str2 is one of it's subset or not 

    RATHER WE COULD BE CHANGING STR2 only by doing the operation backward i.e seeing if a (char in str2 - 1) == (char in str1) OR if (char in str1 == char in str2) then we're moving forward to finding if after applying backward operation on str2 if it's a subset of str1 or not 
*/

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        int ind = 0; //for str2
        for(int i = 0; i < n1; i++) {
            if(ind == n2) return true;
            if(str1[i] == str2[ind]) ind++;//char same
            else if(str2[ind]-1 == str1[i]){
                ind++;
            }//char can be converted
            else if(str1[i] == 'z' && str2[ind] == 'a') ind++; //a can be converted to z
        }
        if(ind == n2) return true;
        return false;
    }
};