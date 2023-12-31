// leetcode : 162

/* Q> given is : unsorted array, arr[i] != arr[i+1], arr[-1] = arr[n] = -infinity,
peak elem > strictly greater than it's neighbours, there can be multiple peaks, there can be duplicates. */

// self approach:
/* Approach( without check fn ): if peak found > return ind, if arr[mid] is not peak, either peak appears in left/right > which side ? > if(arr[lo] >= arr[mid]) >
there is an inc in value : 2 options > either there is peak in bwtn OR arr[lo] itself is peak(if from mid to lo > all elem are S.I), similar is for right side

NOT if both (arr[lo] < arr[mid] > arr[hi]) => which side is peak ? => since mid is not peak > either one of it's neighbour is greater than mid OR both it's neighbour are greater than mid > then there could be a possibility of peak in between => 
bcz from either/both of mid's neighbour val dec to lo/hi => so go that side where
there is a dip at arr[lo] or arr[hi] */

/*--------------------------------------------------------------------------------*/

/* WHY Couldn't using the check fn ? 
    => bcz to explore LEFT : we return 1 and even if that ans is not correct : it is saved in ans
    => BUT if we're sure that ans LEFT contains ans > then we should care if ans is updated to wrong initially bcz finally it will be updated with valid ans.

    => updates reqd in check fn is : if ans is a valid one > STOP : bcz further searching : might update it to smt else and without being updated to again the correct one : process might stop > leaving us with the wrong ans.
*/

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int lo = 0, hi = n-1, ans;
        if(n == 1) return 0; // single elem

        while(lo <= hi) {
            int mid = (lo + hi)/2;
            
            if(mid == 0) {
                if(arr[mid] > arr[mid+1]) {
                    ans = mid;
                    break;
                }
                else {
                    // move right
                    lo = mid+1;
                    continue;
                }
            }    
            else if(mid == n-1) {
                if(arr[mid-1] < arr[mid]) {
                    ans = mid;
                    break;
                }
                else {
                    // arr[mid-1] > arr[mid] > move left
                    hi = mid-1;
                    continue;
                }
            }
            else if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1]) {
                ans = mid;
                break;
            }
            else {
                // mid is not the peak
                /* determine : which way to move to look for peak */
                if(arr[lo] > arr[mid]) {
                    /* move left: bcz probability of finding a peak in left
                    + if can't find(when lo..hi is SD then arr[lo] is the 
                    peak) */
                    hi = mid-1;
                }
                else if(arr[mid] < arr[hi]) {
                    // move right 
                    lo = mid+1;
                }
                else {
                    // both arr[hi] and arr[lo] are smaller than arr[mid]
                    if(arr[mid] < arr[mid+1]) {
                        // move right : dip will be in right
                        lo = mid+1;
                    }
                    else if(arr[mid-1] > arr[mid]) {
                        // move left : dip will be in left
                        hi = mid-1;
                    }
                }
            }
        }
        return ans;
    }
};

// IMP:
/* approach: 
- if mid is peak > return it
- if mid is not the peak, 
    if(arr[mid-1] > arr[mid]) => doesn't matter what val is arr[lo], peak is in left side (either peak in between OR peak in extreme left)
    
    if(arr[mid] < arr[mid+1]) => doesn't matter what val arr[hi] holds, peak is in right side.
 */
// Discussion section > solution: 

    if(nums.length == 1) return 0; // single element

    int n = nums.length;

    // check if 0th/n-1th index is the peak element
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1] > nums[n-2]) return n-1;

    // search in the remaining array
    int start = 1;
    int end = n-2;

    while(start <= end) {
        int mid = start + (end - start)/2;
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
        else if(nums[mid] < nums[mid-1]) end = mid - 1;
        else if(nums[mid] < nums[mid+1]) start = mid + 1;
    }
    return -1; // dummy return statement

// solution 3:

/* Intuition -
As nums[i] != nums[i + 1] Every subarray we select has a peak element(atleast first or last element as nums[-1] = nums[n] = -∞) .
Peak may be there in rejected subarray but we are sure it's present in selected subarray as we have above 2 constraints. */

int findPeakElement(vector<int>& nums) {
    int n=size(nums), l=0, h=n-1;
    while(l < h){ // l<=h when u are expecting to return from loop itself
        int m=(l+h) >> 1;
        if(nums[m+1] > nums[m])
            l = m+1;
        else
            h = m; //m is still part of selected subarray as m+1 is possible peak
    }
    return l;
}