/* Color Balls: maximum no of baskets that can be filled by putting atleast 'k' different color balls in each basket */

/* Approach: BS on answers on 'k': lo = 0, hi = N/k atmax this could be the no of filled baskets. 
check[]: ...1111100000... find last occurence of 1 since maximum filled baskets to find. 

now how do we know: if we can fill 'mid' no of baskets each with 'k' distinct balls.
- create a map to store the frequency of each ball. 
- Now this ball can be placed atmax 'mid' no of times, 1 in each basket, considering we've <= mid balls of this color. Else just
place 'mid' balls, one in each basket. 
- Do this for every ball and we'd never end up placing same color ball in same basket, AND by end if all 'mid' baskets are filled
then 'mid' is probable ans. so we look for bigger mids. 
*/

#include <iostream>
#include <unordered_map>
using namespace std;
using lli = long long;

int arr[100100];
int n,k;

int check(int x, unordered_map<int,int> &mp) {
    /* can we place atleast 'k' distinct elem in each basket, us having 'x' baskets ?
    at max for each type of ball: we can use atmax 'mid' balls of that type, placing 1 in each basket to not have any repeatition
    of placing same type of ball in same basket. 
    Do this for all types of balls. Find out if we can atleast fill 'x' baskets or not. */
    
    lli cnt = k*x; /* k*x places for the balls to fill in */
    
    for(auto it: mp) {
        if(it.second <= x) {
            cnt -= it.second;
        }    
        else {
            cnt -= x;
        }
    }
    
    return cnt <= 0; /* else: there is still space in basket: so we couldn't fill 'x' baskets */
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        
        unordered_map<int,int> mp; // elem: cnt 
        
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        
        int lo = 0, hi = n/k, ans = 0; /* 
        for ...000000.... cannot fill 'x' baskets, each with atleast 'k' distinct elems: so we can fill '0' baskets */
        while(lo <= hi) {
            int mid = (lo+hi)/2;
            if(check(mid, mp)) {
                // save ans and search right
                ans = mid;
                lo = mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}