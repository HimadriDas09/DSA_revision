/* so when will max water be stored: when distance is large and each of their
is also large. So we initially start at both the extremes and then decrease
len such that we get bigger len lines */
class Solution {
public:
// TC: O(n)
    int maxArea(vector<int>& height) {
        int n = height.size(), i = 0, j = n-1; 
        int water = 0;
        while(i < j) {
            int cur = min(height[j], height[i])*(j-i);
            water = max(water, cur);
            if(height[i] > height[j]) {
                // then maybe dec j, I might get a bigger j
                j--;
            }
            else {
                // maybe inc i, I might a bigger i
                i++;
            }
        }
        return water;
    }
};