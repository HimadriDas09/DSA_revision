/* to count no of occurences of an elem in a sorted array > find the last and first occurence of the elem
> last-first+1 is the ans */
int firstOccurence(vector<int> &arr, int n, int x) {
//returns the ind of the first occurence
	int low = 0, high = n-1, ans = -1;
	while(low <= high) {
		int mid = (low+high)/2;
		if(arr[mid] == x) {
			//this ind could be my ans but since I need first occurence > i'll further search left
			ans = mid;
			high = mid-1;
		}
		else if(arr[mid] < x) {
			//search in right
			low = mid+1;
		}
		else {
			//search in left
			high = mid-1;
		}
	}
	return ans;
}
int lastOccurence(vector<int> &arr, int n, int x) {
//returns the ind of the last occurence
	int low = 0, high = n-1, ans = -1;
	while(low <= high) {
		int mid = (low+high)/2;
		if(arr[mid] == x) {
			//this ind could be my ans but since I need last occurence > i'll further search right
			ans = mid;
			low = mid+1;
		}
		else if(arr[mid] < x) {
			//search in right
			low = mid+1;
		}
		else {
			//search in left
			high = mid-1;
		}
	}
	return ans;	
}
pair<int,int> firstAndLastOccurence(vector<int> &arr, int n, int x) {
	int first = firstOccurence(arr, n, x);
	if(first == -1) return {-1, -1};//bcz if first doesn't exist then so does the last
	return {first, lastOccurence(arr, n, x)};
}
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	pair<int,int> ans = firstAndLastOccurence(arr, n, x);
	if(ans.first == -1) {
		//i.e first occurence of the elem doesn't exists > so the elem doesn't exists
		return 0;
	}
	return ans.second - ans.first + 1;
}
