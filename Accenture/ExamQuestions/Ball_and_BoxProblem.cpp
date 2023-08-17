#include<iostream>
#include<math.h>
using namespace std;
//CORRECT SOLN : 2023 offcampus 
/* n boxes each having some balls > for each of the boxes we need (ind+1)sqare no of balls so return total no of additional balls we need */

int NumberOfBalls(int arr[], int n) {
    if(n == 0) return -1;
    int sum = 0;
    /* for each elem > find need = (ind+1)^2 and add difference of (need-have) 
    to sum and return sum*/
    for(int i = 0; i < n; i++) {
        int need = pow(i+1, 2);
        sum += (need-arr[i]);
    }
    return sum;
}

int main()
{   
    int n;
    cout << "enter size of the array : ";
    cin >> n;
    int* arr = new int[n];
    cout << "enter the elem of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    } 
    cout << "ans: " << NumberOfBalls(arr,n) << endl;
    return 0;
}