/* approach: keep on merging the array until you've sorted array i.e
a single elem which is always sorted, then apply the code of merge
2 sorted arrays */

// TC: O(n*logn) => since we're dividing the elem into 2 halves untill we've 1 sized array: so that takes logn operations && for each of the divided array we're merging 2 sorted arrays : that i.e nearly O(n), not always O(n)

void mergeTwoSortedArrays(int s1, int e1, int s2, int e2, int* arr) {
    // create a third array of size : sum of size of 2 arrays
    int n1 = e1-s1+1, n2 = e2-s2+1;
    int* temp = new int[n1+n2];
    /* NOTE: in time of copying from temp to arr: since temp ind starts
    from 0 and ends at e2-s1, so while copying 
    arr[s1...e2] = temp[ind-s1] */
    int i = s1, j = s2, k = 0;

    while(i <= e1 || j <= e2) {
        // handle if one of them exhausts
        if(i <= e1 && j <= e2) {
            if(arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++, k++;
            }
            else {
                temp[k] = arr[j];
                j++, k++;
            }
        }
        else if(i <= e1) {
            temp[k] = arr[i];
            i++, k++;
        }
        else {
            temp[k] = arr[j];
            j++, k++;
        }
    }
    // sorted result of both arrays are kept in a separate array
    // copy back to org array
    for(int i = 0; i < n1+n2; i++) {
        arr[i+s1] = temp[i];
    }
    delete temp;
}

void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here
    // bc
    if(l >= r) return; // bcz no elem and 1 elem is sorted on it's own

    // sc
    int mid = (l+r)/2;

    mergeSort(arr, l, mid); // mS will sort this part
    mergeSort(arr, mid+1, r); // mS will sort this part

    mergeTwoSortedArrays(l, mid, mid+1, r, arr);
}