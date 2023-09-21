class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        vector<int> temp;
        temp.push_back(arr[0]);
        int len = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] > temp.back()) {
                // LIS : so check for greater 
                /* if cur elem will attach at back of LIS or at 
                some other pos */
                temp.push_back(arr[i]);
                len++;
            }
            else {
                int ind = lower_bound(temp.begin(), temp.end(), arr[i])-temp.
                begin();
                temp[ind] = arr[i];
            }
        }
        return len;
    }
};