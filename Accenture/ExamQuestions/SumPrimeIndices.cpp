#include<iostream>
using namespace std;
/* Question : Calculate the sum of nos present at prime indices 
NOTE : 1 is not a prime no
    : if arr is empty return -1
*/
bool checkPrime(int n) {
    if(n <= 1) return false;

    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
int SumPrimeIndices(int* arr, int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(checkPrime(i)) sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;
    cout << "enter the size of the array : ";
    cin >> n;
    int* arr = new int[n];
    cout << "enter the elem of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "ans : " << SumPrimeIndices(arr, n) << endl;
    return 0;
}