#include<iostream>
using namespace std;
/*QUESTION : replace each elem of the array with the nearest smaller present on the right side of that element and then return the array
NOTE : replace elem with -1 if no smaller no is present on the right of the elem
    : return NUll is array is NULL
*/
int* nextSmallerElement(int* arr, int n) {
    // for each elem at ind i, search from i+1...n-1 if a smaller elem is found replace arr[i] with it and break from inner loop else if not found , replace arr[i] with -1
    if(n == 0) return NULL;

    for(int i = 0; i < n; i++) {
        int j = i+1;
        for(; j < n; j++) {
            if(arr[i] > arr[j]) {
                arr[i] = arr[j];
                break;
            }
        }
        if(j == n) {
            // i.e had to go till n > i.e before that smaller elem not found : so replace it with -1
            arr[i] = -1;
        }
    }
    return arr;
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
    int* ans = nextSmallerElement(arr, n);
    if(ans == NULL) cout << "resultant array is NULL" << endl;
    else {
        cout << "modified array : ";
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}