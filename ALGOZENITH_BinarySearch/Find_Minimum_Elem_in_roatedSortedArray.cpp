// tc: O(log n)

/* min in rotated sorted array : 
i.e arr[ind of min elem] == arr[how many times the array has been rotated]

=> design a check fn > that'll give you a monotonic space  */ 
class Solution {
public:
/* check fn > creates a monotonic space : [0,0,....0,1,1,1...1]
and the ind of the first 1 is our ans > which we can find using BS */
    int check(int mid, vector<int> &nums) {
        return nums[mid] < nums[0]; 
        /* if it's a right rotated array > then from min elem to last elem
        we should've 1 and rest have 0 
        But if array is sorted > then check[] = {0,0,....0} 
        so by default ans should be the 0th elem */
    } 
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1;
        int ans = nums[0]; 
        /* default ans (decide after creating the check fn) */

        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(check(mid, nums) == 1) {
                ans = nums[mid];
                // explore left for better 1
                hi = mid-1;
            }
            else {
                // explore right for first 1
                lo = mid+1;
            }
        }
        return ans;
    }
};