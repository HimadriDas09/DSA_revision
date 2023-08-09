//Direct Binary Search Approach: 1 
/* array is sorted > ans = -1 && look out for k using BS 
    for last position : 
    if arr[mid] == k > mid is probably the 1st ind but i'll still look 
    in the left 
    similarly for last position > after getting a probable ind, u still
    look in the right
*/
int firstOccurence(vector<int> &arr, int n, int x) {
    int low = 0, high = n-1, first = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == x) {
            //mid is probably my ind
            //But since I need the first ind > i'll look in left
            first = mid;
            high = mid-1;
        }
        else if(arr[mid] > k) {
            //look in left
            high = mid-1;
        }
        else {
            //look in right
            low = mid+1;
        }
    }
    return first;
}
int lastOccurence(vector<int>&arr, int n, int x) {
    int low = 0, high = n-1;
    int last = -1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(arr[mid] == x) {
            //mid is probably my ind
            //But since I need the last ind > i'll look in right
            last = mid;
            low = mid+1;
        }
        else if(arr[mid] > k) {
            //look in left
            high = mid-1;
        }
        else {
            //look in right
            low = mid+1;
        }
    }
    return last;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = firstOccurence(arr, n, k);
    if(first == -1) return {-1, -1};//very imp > if first not present then last also not present so don't waste another logn
    int last = lastOccurence(arr, n, k);
    return {first, last};
}

//APPROACH 2
//LowerBound and UpperBound code usage: 
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int lb = lowerBound(arr, n, k);
    if(lb == n || arr[lb] != k) return {-1, -1};/* bcz if that 
    elem is not present then fo and lo is -1 both */
    return {lb, upperBound(arr, n, k)-1}; /* first occurence is pointed
    by lb && if elem is present then ub-1 rep the last occurence */ 
}

