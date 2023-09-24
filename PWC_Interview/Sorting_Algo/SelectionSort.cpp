#include<iostream>
using namespace std;

// best, worst, average case TC: O(n2)

/* approach: find the min elem in the search space and swap it with the starting 
elem of the search space */
void selectionSort(int arr[], int n) {

    for(int i = 0; i < n; i++) {
        int min_ind = i;
        for(int j = i; j < n; j++) {
            if(arr[j] < arr[min_ind]) min_ind = j;
        }           
        swap(arr[i], arr[min_ind]);
    }

}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    selectionSort(arr, n);

    cout << "sorted array : ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}