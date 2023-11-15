/* find no of integers x(<= n) such that difference(x & sum of its digits) >= s 
Since as we increase value of x the difference will increase which is still >= s. 


so check[] = ....0000011111.... => so find the pos of 1st occurence of 1. then n-ind+1 is the no of x's 
lo = 1, hi = n, ans = ; so When will check[]: ..00000.... then cannot find 1: so default count should be 0, so according
to it adjust the ans.

it will fail when s > n (then a no which is <= n - its digts will not be able to exceed s)*/

#include <iostream>
using namespace std;
using lli = long long;

lli n,s;

int check(lli x) {
    // check if x - (sum of its digits) >= s or not 
    lli digit_sum = 0;
    lli no = x;
    while(no > 0) {
        digit_sum += (no%10);
        no /= 10;
    }
    return x-digit_sum >= s;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        
        lli lo = 1, hi = n, ans = n+1; // default cnt 
        while(lo <= hi) {
            lli mid = (lo+hi)/2;
            if(check(mid)) {
                // save ans and check left for 1st occurence of 1 
                ans = mid;
                hi = mid-1;
            }
            else {
                // check right for 1 
                lo = mid+1;
            }
        }
        cout << n-ans+1 << endl;
    }

    return 0;
}