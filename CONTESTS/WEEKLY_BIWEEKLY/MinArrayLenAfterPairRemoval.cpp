#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*ANS correct but giving TLE */

int minLengthAfterRemovals(vector<int>& nums) {
    int n = nums.size(), len = 0; // len of updated temp
    vector<int> temp;
    for(auto it:nums) temp.push_back(it);
    // cout << "0" << endl;
    while(n > len) {
        if(len != 0) {
            n = len;
            // cout << "1" << endl;
        }
        int i = 0, ind = 0;
        while(ind < n) {
            if(ind == n-1 || temp[ind] == temp[ind+1]) {
                temp[i] = temp[ind];
                ind++, i++;
                // cout << "2" << endl;
            }
            else if(temp[ind] < temp[ind+1]) {
                ind += 2;
                // cout << "3" << endl;
            }
            else {
                // cout << "4" << endl;
            }
        }
        // cout << "5" << endl;
        len = i;
    }
    // cout << "6" << endl;
    return len;
}

int main()
{
    vector<int> arr = {1,1,2};
    int ans =  minLengthAfterRemovals(arr);
    cout << "ans: " << ans << endl;
    return 0;
}