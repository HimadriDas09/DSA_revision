#include<iostream>
using namespace std;
// fine no : take diff of greatest no from one array and smallest array such the difference is maximum

static int fineNumber(int a[], int b[], int n, int m) {
    //find the smallest in both and the largest in both 
    //calculate both the diff and return the min
    int s1 = INT_MAX, s2 = INT_MAX, l1 = INT_MIN, l2 = INT_MIN;
    for(int i = 0; i < n; i++) {
        s1 = min(s1, a[i]);
        l1 = max(l1, a[i]);
    }
    for(int i = 0; i < m; i++) {
        s2 = min(s2, b[i]);
        l2 = max(l2, b[i]);
    }
    return max(l1-s2, l2-s1); /* i.e diff of largest in one arr and smallest in 
    other array is what was asked > but we were not sure whose largest to take and
    whose smallest to take > so we did for both and returned the max */
}

int main()
{
    int n, m;
    cout << "enter size of arr1 : ";
    cin >> n;
    cout << "enter size of arr2 : ";
    cin >> m;
    int* arr1 = new int[n];
    int* arr2 = new int[m];
    cout << "enter arr1 elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    cout << "enter arr2 elements : ";
    for(int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    cout << "ans: " << fineNumber(arr1,arr2, n, m) << endl;
    return 0;
}