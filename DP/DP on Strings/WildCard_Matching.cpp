/*QUESTION > 2 strings are given : pattern and text > return true if text matches the pattern else false > pattern contains (lowercase + * + ?) && text cotains only (lowercase) 
condition > ? rep a single character and * rep a sequence of consecutive characters
i.e in place of ?(in pattern), a single char can appear (in text) then text follows th pattern, sim in place of *(in pattern), a sequence of char(>= len 0) can appear (in text), then we can say text follows the pattern*/

/*eg : => 
   eg : p = "ab?cd" && t = "abecd" then true
   eg : p = "ab?cd" && t = "abced" then false
      bcz in place of ?, c is ok but rest is not following pattern
   
   eg : p = "ab*cd" && t = "abcd" then true 
      bcz * matches with 0 len string
   eg : p = "ab*ed" && t = "abccd" then false
      bcz "ab" "ab" matches fine, "d" matches fine, but even if "*" rep "cc" in text then "e" cannot be matched to anything, or if "*" rep "c", then other "c" is left. So doesn't match
   
   eg : p = "ab*cd" && t = "abdefcd", * rep def else all char matches so ans : true
*/ 
 
/*APPROACH => 
   if character matches then OK, ? also matches with only 1 char > so we can determine true/false for the ans 
   BUT for " * ", we don't know how many characters does it rep > 0/1/2/3....
   so we'll have to try to each of them and see if text is following pattern or not in any of the cases if it does then ans is true else ans is false

   so RECURSION has to be followed : 
      f(i,j) => p[0...i] matches with t[0...j] 
      i rep character in pattern && j rep char in text.

      if(char matches OR ? in p matches with a char in t) then reduce both the strings by 1 and make a call on that part

      else if(a * is encountered in pattern) {
         //now we need to try all the ways i.e * rep 0 len char in text
         > making RC : f(i-1, j)
         //* rep 1 len char in text > RC : f(i-1, j-1);
         // * rep 2 len char in text > RC : f(i-1, j-2);
         ......and so on...
         //So above could be done using a for loop or we can call to some state such that all these calls are already covered

         > we can do 
         return f(i-1, j) | f(i, j-1)
         
         REASON : 
         left call > * in pattern rep 0 len in text
         right call > * still in pattern but 1 char in text is removed
            it's left call > * rep 0 len in text > in this case i & j are such that 
            * is not there and jth char removed in prev RC is also not there 
               so is the case of * rep 1 char
            
            similary in further RC's > we'll encounter cases such that * rep sequence from len 0....bc is hit
      }

      BC > 
      is case of 2 String Comparison > 
         BC is 
         s1 : pattern && s2 : word
         i) when only s1 exhausts
            - now if s2 has exhausted return true;
            else return false
         ii) when only s2 exhausts
            - but i >= 0 then only if those chars in pattern are all "*" then only return true else ans is false
*/

#include<bits/stdc++.h>
//space optimization 
bool spaceOptimization(string &pattern, string &text) {
   int n = pattern.size();
   int m = text.size();

   vector<bool> prev(m+1, false), cur(m+1, false);

   //bc
   prev[0] = true;
   for(int j = 1; j <= m; j++) prev[j] = false;
   //for i = 1 -> n && j == 0 > handle inside the nested loops

   for(int i = 1; i <= n; i++) {
      //base case => i > 0 && j == 0 handle
      bool fl = true;
      for(int ii = 1; ii <= i; ii++) {
         if(pattern[ii-1] != '*') {
            fl = false;
            break;
         }
      }      
      cur[0] = fl;
      for(int j = 1; j <= m; j++) {

         if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') {
            cur[j] = prev[j-1];
         }
         else if(pattern[i-1] == '*') {
            /*then we have many options > '*' in s1 could match 
            with len 0 to any len in s2*/
            cur[j] = cur[j-1] | prev[j];
         }
         else{
            //not match
            cur[j] = false;
         }
      }
      prev = cur;
   }
   return prev[m];
}
//memoisation > 1 based indexing for tabulation
int f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp) {
   //bc
   //if s1 exhausts
   if(i == 0 && j == 0) return true;//all char matched
   if(i == 0 && j > 0) return false;//cannot match s2 with anything
   //if s2 exhausts
   /*then s1 & s2 could still match only if all the chars in s1 are '*' */
   if(j == 0 && i > 0) {
      for(int ii = 1; ii <= i; ii++) {
         if(pattern[ii-1] != '*') return false;
      }
      return true;
   }

   if(dp[i][j] != -1) return dp[i][j];
   //match
   if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') return dp[i][j] = f(i-1, j-1, pattern, text, dp);

   else if(pattern[i-1] == '*') {
      /*then we have many options > '*' in s1 could match 
      with len 0 to any len in s2*/
      return dp[i][j] = f(i,j-1, pattern, text, dp) | f(i-1, j, pattern, text, dp);
   }

   //not match
   return dp[i][j] = false;
}
bool tabulation(string pattern, string text)
{
   // Write your code here.
   /*pattern contain lowercase + * + ? && text contain only lowercase*/
   int n = pattern.size();
   int m = text.size();
   //memoisation > dp[n][m]
   // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
   // return f(n, m, pattern, text, dp);

   //tanulation
   vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));
   //base case
   dp[0][0] = true;

   for(int j = 1; j <= m; j++) dp[0][j] = false;

   for(int i = 1; i <= n; i++) {
      //compute dp[i][0];
      bool flag = true;
      for(int ii = 1; ii <= i; ii++) {
         if(pattern[ii-1] != '*') {
            flag = false;
            break;
         }
      }
      dp[i][0] = flag;
   }

   //copy the recurrence
   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {

         if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') {
            dp[i][j] = dp[i-1][j-1];
         }
         else if(pattern[i-1] == '*') {
            /*then we have many options > '*' in s1 could match 
            with len 0 to any len in s2*/
            dp[i][j] = dp[i][j-1] | dp[i-1][j];
         }
         else{
            //not match
            dp[i][j] = false;
         }
      }
   }
   return dp[n][m];
}

/********************************************************************************/
//memoisation : 0 based indexing
int f(int i, int j, string &pattern, string &text, vector<vector<int>> &dp) {
   //bc
   //if s1 exhausts
   if(i < 0 && j < 0) return true;//all char matched
   if(i < 0 && j >= 0) return false;//cannot match s2 with anything
   //if s2 exhausts
   /*then s1 & s2 could still match only if all the chars in s1 are '*' */
   if(j < 0 && i >= 0) {
      for(int ii = 0; ii <= i; ii++) {
         if(pattern[ii] != '*') return false;
      }
      return true;
   }

   if(dp[i][j] != -1) return dp[i][j];
   //match
   if(pattern[i] == text[j] || pattern[i] == '?') return dp[i][j] = f(i-1, j-1, pattern, text, dp);

   else if(pattern[i] == '*') {
      /*then we have many options > '*' in s1 could match 
      with len 0 to any len in s2*/
      return dp[i][j] = f(i,j-1, pattern, text, dp) | f(i-1, j, pattern, text, dp);
   }

   //not match
   return dp[i][j] = false;
}
bool wildcardMatching(string pattern, string text)
{
   // Write your code here.
   /*pattern contain lowercase + * + ? && text contain only lowercase*/
   int n = pattern.size();
   int m = text.size();
   //memoisation > dp[n][m]
   vector<vector<int>> dp(n, vector<int> (m, -1));
   return f(n-1, m-1, pattern, text, dp);
}
