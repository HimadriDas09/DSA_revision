#include<iostream>
using namespace std;

//question: till some ind i > subarray is inc and after that it is dec > so till it find the sum and from i till n-1 find the sum > multiply both the sums and return > if n < 3 return -1 
int multiplySubarraySum(int *arr, int &n) {
    int incSum = 0, decSum = 0;
    //approach : just find the peak ind 
    int ind = 0;// bcz 0th elem is a part of inc Subarray
    for(int i = 0; i < n-1; i++) {
        if(arr[i] <= arr[i+1]) ind = i+1;
        else break;
    }
    //so ind contains peak ind
    for(int i = 0; i < n; i++) {
        if(i <= ind) incSum += arr[i];
        if(i >= ind) decSum += arr[i];
    }
    return incSum*decSum;
}

int main()
{
    int n;
    cout << "enter array size : ";
    cin >> n;
    int* arr = new int[n]; //dynamic array allocation
    cout << "enter the array : " << endl;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if(n < 3) cout << "array size should be >= 3";
    else cout << "ans : " << multiplySubarraySum(arr, n) << endl;
    return 0;
}