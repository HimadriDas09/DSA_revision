// #include <bits/stdc++.h> 
#include<vector>
#include<iostream>
using namespace std;
/*IMPORTANT : 

Question > can you modify atmost 1 elem to convert the array into a non decreasing array i.e arr[i] <= arr[i+1] for i = 0 -> n-2

APPROACH > 
    - traverse the array > if condition satisfied then ok, if not > then use that one operation 
    - now we can use that operatin either arr[i] or arr[i+1] 
        - which one should we choose ? 
        - since we reached ind i > so till ind i arr is in non-dec order > now if we use that one operation on arr[i] (i.e arr[i] = arr[i+1]) then can the non-dec behavior till ith changes ? 
            - could change => so check i.e if(arr[i-1] <= arr[i]) then fine > else using one operation on arr[i] to modify it > doesn't make whole arr nondec
        -option 2 > what if we change arr[i+1] i.e arr[i+1] = arr[i] (we cannot just modify it with any no, we're doing it to maintain non dec behavior && rather than assigning a greater or smaller no it's better to assign equal no else might not be non dec) => so till arr[i+1] it is non dec but maybe bcz of the prev value of arr[i+1] there was non dec order from i+1 -> end which might just be broken bcz of new value assigned > so iterate and check it it' broken or not

    - so basically > if condition not satisfied > 2 choices > either change arr[i] or arr[i+1]
        - so changed arr[i] check at arr[i-1] if still non dec 
        YES > proceed to check in further part of the arr considering we used the 1 modification.
        NO > then we don't change it : we just change arr[i+1] then.
        - OR changed arr[i+1] still proceed to checking in further part of the arry considering we used 1 modification .

        OBSERVATION > we're doing some same stuff in both the cases > So rather > always change arr[i] && based on if(arr[i-1] <= arr[i]) {yes fine, and check the rest part of the array} else {considering not changing arr[i], changing arr[i+1] and check from i+2 to n-1}
*/
bool isPossible(int *arr, int n)
{
    //  Write your code here.
    int canmodify = 1;
    bool ans = true;
    int i = 0;
    while(i < n-1) {
        if(arr[i] <= arr[i+1]) {
            i++;
        }

        else if(arr[i] > arr[i+1] && canmodify) {
            int oldVal = arr[i];
            arr[i] = arr[i+1];
            canmodify = !canmodify;
            //i.e changed arr[i] but non dec behavior till i is not valid anymore
            if(arr[i-1] > arr[i]) {
                //now consider arr[i+1] = older value of arr[i] && traverse from i+1 -> n-2 > if condition fails > then ans = false else ans = true;
                arr[i] = oldVal; //revert changes
                canmodify = !canmodify;
                arr[i+1] = arr[i]; //again used 1 modification
                canmodify = !canmodify;
            }
            //else if above situation doesn't happen still we traverse from i+1 -> n-2
            i++;
        }
        else {
            //i.e want to modify but can't modify
            ans = false;
            break;
        }
    }
    return ans;
}
int main() {
    int arr[] = {8,4,6};
    int n = 3;
    bool ans = isPossible(arr, n);
    cout << "ans : " << ans << endl;
    return 0;
}