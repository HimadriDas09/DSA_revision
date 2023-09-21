#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// cnt no of subsequences: pick and notpick approach
/* cnt(ind) returns no of unique subsequences having equal no of zeros and ones */
int cnt(int ind, int z, int o, unordered_set<string> &st, string sub, string str) {
    // bc
    if(ind < 0) {
        if((z == o && z > 0 && o > 0) && !st.count(sub)) {
            st.insert(sub);
            cout << sub << endl;
            return 1; // since unique subsequence : so 1 subsequence found
        }
        return 0;
    }

    // sc
    // not include elem
    int np = cnt(ind-1, z, o, st, sub, str);

    // include elem
    if(str[ind] == '0') z++;
    else o++;
    sub += str[ind];
    int p = cnt(ind-1, z, o, st, sub, str); // yet to include unique subsequence in the set: check it in bc that if it's unique or not

    return np + p;
}

int f(string str) {
    int n = str.size();
    unordered_set<string> st;
    return cnt(n-1, 0, 0, st, "", str);
}

int main()
{
    string str;
    cout << "enter binary string : " << endl;
    cin >> str;
    cout << f(str) << endl;

    return 0;
}