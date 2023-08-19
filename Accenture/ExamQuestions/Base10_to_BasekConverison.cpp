#include<bits/stdc++.h>
class Solution {
public:
    int sumBase(int n, int k) {
        vector<int> rev;
        while(n > 0) {
            rev.push_back(n % k);
            n /= k;
        }
        //vector contains no in rev order after converting to base k
        int ans = 0;
        for(int i = 0; i < rev.size(); i++) {
            ans += rev[i];
        }
        return ans;
    }
};