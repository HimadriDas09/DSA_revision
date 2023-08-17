#include<iostream>
using namespace std;
/* Question : find F1 = (f(arr[0]) + f(arr[1]) + .....) % 10 where f(x) = sum of digits of an integer
and F2 = (sum of elem of the array) % 10 and return f = F1-F2 */
int sumOfDigits(int n) {
    if(n < 0) n = abs(n); //-ve made +ve to add up digits
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int differenceSumOfDigits(int* arr, int n) {
    int f1 = 0, f2 = 0;
    for(int i = 0; i < n; i++) {
        f1 += sumOfDigits(arr[i]);
        f2 += arr[i];
    }
    f1 = f1%10, f2 = f2%10;
    return f1-f2;
}

int main()
{
    int n;
    cout << "enter the size of the array : ";
    cin >> n;
    int* arr = new int[n];
    if(n <= 0) {
        cout << "enter n greater than 0" << endl;
    } 
    else{
        cout << "enter the elem of the array : ";
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << " ans : " << differenceSumOfDigits(arr,n) << endl;
    }
    
    return 0;
}