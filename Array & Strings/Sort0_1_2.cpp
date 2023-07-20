// Approach 1
// TC : O(N)
#include <bits/stdc++.h>
void sort012(int *arr, int n)
{
    //   Write your code here
    int ind = 0, i = 0, j = n - 1;
    while (ind < n)
    {
        if (arr[ind] == 0)
        {
            if (ind > i)
            {
                /*if ind <= i : then no meaning in swapping bcz that pos
                already contains 0*/
                swap(arr[ind], arr[i]);
                i++;
            }
            else
            {
                /* arr[ind] == 0 && ind <= i => so just ind++, i++*/
                ind++, i++;
            }
        }
        else if (arr[ind] == 2)
        {
            if (ind < j)
            {
                /* if ind >= j then those pos already contains 2 so why
                swapping */
                swap(arr[ind], arr[j]);
                j--;
            }
            else
            {
                ind++, j--;
            }
        }
        else
        {
            ind++;
        }
    }
}

//Approach 2
void sortColors(vector<int>& nums) {
    int low=0, mid=0, high=nums.size()-1;

    //All numbers to left of low are 0
    //All numbers to right of high are 2

    while(mid<=high){
        if(nums[mid]==0)
            swap(nums[low++], nums[mid++]);
        else if(nums[mid]==1)
            mid++;
        else
            swap(nums[mid], nums[high--]);
    }
}