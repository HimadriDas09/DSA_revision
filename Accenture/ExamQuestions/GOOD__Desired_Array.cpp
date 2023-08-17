#include<iostream>
#include<vector>
using namespace std;

/* Desired Array : given k,n,arr > find first 'k' elem which are not divisible by
all of the elem present in the array. */

/* approach > for every elem from 1....INT_MAX > check for each of the array elem 
if it's not div by all of them then inc it in resulting array */ 
vector<int> desiredArray(int n, int k, int* arr) {
    vector<int> ans;
    for(int i = 1; i <= 1e9; i++) {
        if(ans.size() == k) break; //ans contains k elems
        for(int j = 0; j < n; j++) {
            if(i % arr[j] != 0) {
                //i not div by arr[j] 
                if(j == n-1) ans.push_back(i);/* i is div by all the elem of arr*/
                continue;
            }
            else {
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "enter the size of the array : ";
    cin >> n;
    cout << "enter the value of k : ";
    cin >> k;
    int* arr = new int[n];
    cout << "enter array elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum = 0;
    vector<int> ans = desiredArray(n,k,arr);
    for(auto it : ans) {
        sum += it;
    }
    cout << endl;
    cout << "sum : " << sum << endl;
    return 0;
}