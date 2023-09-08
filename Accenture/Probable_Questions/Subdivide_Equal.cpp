#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestFactor(int no) {
    int ans = -1;
    for(int i = no-1; i > 1; i--) {
        if(no % i == 0) return i;
    }
    return ans;
}

int SubdivideEqual(int no) {
    //bc
    if(no == 1) return 0;

    //sc
    int factor = largestFactor(no);
    
    int div = INT_MAX;
    if(factor != -1) div = 1 + SubdivideEqual(no/factor);
    int sub = 1 + SubdivideEqual(no-1);

    return min(div, sub);
}

int main()
{
    int n;
    cout << "enter number: ";
    cin >> n;
    cout << "min no of operations: " << SubdivideEqual(n) << endl;
    return 0;
}