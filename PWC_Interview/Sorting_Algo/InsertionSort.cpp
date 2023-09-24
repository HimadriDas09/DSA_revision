#include<iostream>
using namespace std;

// Worst, Average : TC: O(n2) && Best : TC : O(n)

/* app: take an elem and place it at it's correct position 

initially we consider the 1 sized arr i.e till ind 0(place all elem at their 
correct pos), then consider till ind 1(place everything at correct pos), then till ind 2(place everything at thier correct pos > how? > by swapping with left > why does that work ? > bcz the left is already sorted : so by swapping with greater in left, we can make it reach it's correct pos) */

void insertionSort(int arr[], int n) {
    // we move from end to beg of the selected array
    for(int end = 0; end < n; end++) {

        // from arr[0..0] is already sorted
        for(int i = end; i > 0; i--) {
            if(arr[i-1] > arr[i]) swap(arr[i], arr[i-1]);
            else break; // left is smaller so arr[i] is at it's correct pos.
        }
    }
}

int main()
{
    int n; 
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    insertionSort(arr,n);

    cout << "sorted array : ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}