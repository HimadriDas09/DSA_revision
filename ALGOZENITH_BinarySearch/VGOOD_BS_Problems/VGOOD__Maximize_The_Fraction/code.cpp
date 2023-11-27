#include<bits/stdc++.h>
#include<queue>
using namespace std;
using lli = long long;
using ld = long double;
#define hi_limit 1000000000

int A[100100], B[100100];
int n, k;

/* check if >= x ratio can be maintained if I take ratio of any k elem of A to corresponding k elem of B. 
app: since eq is (Sum of Ai)/(Sum of Bi) = x
so, sum of (Ai-XBi) = x; 
put (Ai-XBi) in a pq for all 'n' elems: and take the biggest 'k' ones out of 
pq: if sum is >= x then greater ratio is possible so return 1;
    HOW DO YOU DO THAT? 
        - create a min heap: for all the n elem: as soon as pq.size() > k, remove the top elem: do this for throughout all elem: by the end our pq has largest 'k' elems
        
else return 0;

pq: push,pop,emplace : O(logN). Else O(1)
*/
int check(ld x) {
    priority_queue<ld, vector<ld>, greater<ld>> pq;

    for(int i = 0; i < n; i++) {
        ld value = A[i]-(x*B[i]);
        pq.push(value);
        if(pq.size() > k) pq.pop();
    }

    // now pop the top 'k' values
    ld sum = 0;
    while(pq.size()) {
        sum += pq.top();
        pq.pop();
    }

    return sum >= 0;
}

void solve() {
    ld lo = 0.0, hi = hi_limit, ans = 0.0;
    ld EPS = 1e-9;

    // monotonic space: ..111110000..
    while(abs(hi-lo) >= EPS) {
        ld mid = (lo+hi)/2.0;
        if(check(mid)) {
            // go right
            ans = mid;
            lo = mid;
        }
        else {
            // go left
            hi = mid;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> A[i];
        for(int i = 0; i < n; i++) cin >> B[i];

        solve();
    }
    return 0;
}