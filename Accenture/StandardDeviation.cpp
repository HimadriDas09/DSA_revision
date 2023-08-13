#include<iostream>
#include<math.h>
using namespace std;

//2023 offcampus question: calculate standardDeviation : formula is SD = sqrt(((elem[0]-mean)^2 + ....... (elem[n-1]-mean)^2)/n)
/* pow(a,b) takes double as arg and return a double val, sqrt() returns a double val */
//CORRECT SOLUTION 
double StandardDeviation(int arr[], int n) {
    double size = n;
    double sum = 0.0;
    for(int i = 0; i < n; i++) sum += arr[i];
    double mean = sum/size;
    cout << "mean : " << mean << endl;
    double squareSum = 0.0;
    for(int i = 0; i < n; i++) {
        squareSum += pow(arr[i]-mean, 2.0);
    }
    cout << "squareSum : " << squareSum << endl;
    double sd = sqrt(squareSum/size);
    cout << "ans in fn :  " << sd << endl;
    return sd;
}

int main()
{   
    int n;
    cout << "enter the size of the arr: ";
    cin >> n;
    // int arr[n]; > static array cannot be of variable size 
    int* arr = new int[n]; //dynamic array
    cout << "enter the elements of the array : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "standard deviation : " << StandardDeviation(arr, n) << endl;
    return 0;
}