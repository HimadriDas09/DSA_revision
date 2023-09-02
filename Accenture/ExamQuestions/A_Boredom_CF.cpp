// for optimized : refer to u tube



// TLE solution

#include<iostream>
#include<unordered_map>
using namespace std;

/* f(i, mp) : returns max profit from ind 0....i mp rep what elems are currently in array */
int f(int ind, unordered_map<int,int> mp, int* arr) {
    //bc
    if(ind == 0) return 0;

    //sc: take and nottake

    //notake : move to next ind
    int nottake = f(ind-1, mp, arr);

    //take: take elem > delete all occurences of elem-1 and elem+1, then score += arr[ind]
    // also before take: check can take? > bcz if it's not in mp: then it probably got deleted
    int take = 0;
    if(mp.count(arr[ind-1])) {
        mp[arr[ind-1]]--; // operation applied on one occurence of arr[ind]
        if(mp[arr[ind-1]] == 0) mp.erase(arr[ind-1]);

        if(mp.count(arr[ind-1]+1)) mp.erase(arr[ind-1]+1);
        if(mp.count(arr[ind-1]-1)) mp.erase(arr[ind-1]-1);

        // score earned is arr[ind]
        take = arr[ind-1] + f(ind-1, mp, arr);
    }
    return max(take, nottake);
}

int Boredom(int *arr, int n) {
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    return f(n, mp, arr);

}

int main()
{
    int n;
    // cout << "enter size of array: " << endl; 
    cin >> n;
    int* arr = new int[n];
    // cout << "enter the array: " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << Boredom(arr,n) << endl;
    return 0;
}