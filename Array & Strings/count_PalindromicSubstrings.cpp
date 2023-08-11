#include<bits/stdc++.h>
//TC : O(n2)
/* we can explore all the substrings of input and check if they are 
palindrome or not > APPROACH(based on constraints) : considering 
each ind as center of a substring then we can explore both the left and 
right side of the substring to check if it's palindrome or not 
> a char is mid of a palindrom based on that string can be even len palind
or odd len palindrome
> for every palidrome add 1 to cnt
initially one len char is palindrome && from eg: same char but diff
ind is still a diff palindrome */
int palindromicSubstrings(string input)
{
    int n = input.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        //for every char it's a 1 len palindrome
        cnt++;
        //input[i] is odd len palindrome
        int left = i-1, right = i+1;
        while(left >= 0 && right <= n-1) {
            if(input[left] == input[right]) {
                cnt++;//a new palindrome observed
                left--;
                right++;
            }
            else {
                //one above condn fails
                break;
            }
        }
        //input[i] is even len palindrome
        if(input[i] == input[i+1]) {
            //then i and i+1 could be the middle of an even len palindrome
            left = i, right = i+1;
            while(left >= 0 && right <= n-1) {
                if(input[left] == input[right]) {
                    cnt++;//a new palindrome observed
                    left--, right++;
                }
                else {
                    break;
                }
            }
        }
    }    
    return cnt;
}