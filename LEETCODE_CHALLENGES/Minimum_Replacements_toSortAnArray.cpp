// LC hard
// ADHOC type: refer to vivek mittal u tube video to understand

/* Greedy app: into whatever parts we decompose it we need to make sure
that the value of the min elem is maximized : so that further to the next
elem: there is a less chance to decompose it */
/* app: we move from back to front => keep a track of the prev elem as 
maxMinElem, no of parts in which elem is broken is ceil(elem/maxMinElem) 
for this no of opern is above val-1 && maxMinElem for next itern is above val
+ elem % maxMinElem */
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long opern = 0;
        int maxMinElem = nums[n-1];
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] > maxMinElem) {
                int parts = ceil(nums[i]/ (double)maxMinElem);

                // no of operation is parts-1
                opern += parts-1;

                /* what would each elem be: elem/parts and then we add modulo
                part to each elem: still min elem is maximized and extra part
                if there is not added to the min elem */
                maxMinElem = nums[i]/parts;
            }
            else {
                maxMinElem = nums[i];
            }
        }
        return opern;
    }
};