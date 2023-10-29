#include<iostream>
#include<vector>
using namespace std;
using ll = long long;

int check(ll mid, int A, int B, vector<int> &C, int n) {
   // in <= mid time can we paint all walls using <= A painters
   // so each painter is given mid seconds to paint as much he can paint
   int no_of_painters_spawned = 0;
   ll cur_painter_time_left = 0;
   
   for (int i = 0; i < n; i++) {
        ll cur_wall_time = (ll) B*C[i]; 
        if(cur_painter_time_left >= cur_wall_time) {
            // he paints the wall > & his time decreases
            cur_painter_time_left -= cur_wall_time;
        }       
        else {
            /* spawn new painter > who has mid seconds > && even if he
            cannot paint the ith wall with max limit mid time, then no one 
            can so we return 0
            else : we paint the wall && dec his time 
            */
            no_of_painters_spawned++;
            cur_painter_time_left = mid;
            
            if(no_of_painters_spawned > A) return 0;
            if(cur_painter_time_left < cur_wall_time) return 0;
            else {
                // paint the cur wall
                cur_painter_time_left -= cur_wall_time;   
            }
        }
   }
   // we painted all the walls and didnot summon > A painters 
   return 1;
}

// A painters and (each take B units of time to paint 1 unit of board)
// C[i] = len of ith board
int paint(int A, int B, vector<int> &C) {
    ll total_time = 0;
    int n = C.size();
    for(int i = 0; i < n; i++) {
        total_time += (ll) B*C[i];
    }
    ll lo = 0, hi = total_time, ans = -1; 
    
    // find the occurence of 1st 1
    while(lo <= hi) {
        ll mid = lo + (hi-lo)/2;
        
        if(check(mid, A, B, C, n)) {
            // save the ans && search left
            ans = mid;
            hi = mid-1;
        }
        else {
            // find 1 in right
            lo = mid+1;
        }
    }
    return ans%10000003;
}

int main()
{

    return 0;
}