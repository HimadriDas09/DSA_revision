//DOESN'T CONTAIN DUPLICATE ELEMENTS
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == k) return mid;
        
        /* NOTE : we can't do like if arr[mid] < k so sure to search
        in the left half > bcz it's rotated sorted array , so even 
        if above satisfied, k could be in right half
        : SO DETERMINE WHICH HALF TO ELIMINATE */
        if(arr[low] <= arr[mid]) {
            /*left half is sorted > now check if it contains the k
            or not */
            if(arr[low] <= k && k <= arr[mid]) {
                //if k exists then it'll be in left half
                high = mid-1;
            }
            else {
                //k not in left half so in right
                low = mid+1;
            }
        }
        else {
            /* if left half is not sorted then right half is definitely
            sorted > bcz whole arr is sorted && after rotation
            one half is always sorted and one half isn't */
            if(arr[mid] <= k && k <= arr[high]) {
                //if k exists then it's in right side
                low = mid+1;
            }
            else {
                //if k exists then it's not in right side so it's in left
                high = mid-1;
            }
        }
    }
    return -1;
}
