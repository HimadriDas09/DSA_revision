#include<iostream>
using namespace std;

/* work from ind [0..n-1], compare adjacent elem and swap them, such
that the max elem is put to the end of the array i.e at arr[n-1].
now work from ind [0..n-2] and do the same */

// Worst, Average case TC: O(n2)
// Best Case(when array is already sorted) TC : O(n)

void bubbleSort(int arr[], int n) 
{
    /* with each itern end of the array to work on changes */
    for(int i = n-1; i >= 1; i--) {
        int didSwap = 0;
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
        cout << "run" << endl;
    }
}

int main()
{
    int n; 
    cin >> n; 
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);

    cout << "sorted array : ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}