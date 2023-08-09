#include<bits/stdc++.h>
/* Whole process of Binary Search Implemented to find Floor and Ceil */
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	/* ceil : smallest elem >= x
	is basically lower_bound's value */
	sort(arr, arr+n);
	int ans = -1, low = 0, high = n-1;
	while(low <= high) {
		int mid = (low+high)/2;
		if(arr[mid] >= x) {
			//could probably be my ans
			//but since I want the smallest no > i'll futher look left
			ans = arr[mid];
			high = mid-1;
		}
		else {
			//look in right
			low = mid+1;
		}
	}
	int ceil = ans;
	/* floor => largest no <= x */
	ans = -1, low = 0, high = n-1;
	while(low <= high) {
		int mid = (low+high)/2;
		if(arr[mid] <= x) {
			//could probably be my ans
			//but since i want largest > i'll look more in the right
			ans = arr[mid];
			low = mid+1;
		}
		else {
			//look in the left;
			high = mid-1;
		}
	}
	int floor = ans;
	return {floor, ceil};
}
