pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int lb = lowerBound(arr, n, k);
    if(lb == n || arr[lb] != k) return {-1, -1};/* bcz if that 
    elem is not present then fo and lo is -1 both */
    return {lb, upperBound(arr, n, k)-1}; /* first occurence is pointed
    by lb && if elem is present then ub-1 rep the last occurence */ 
}