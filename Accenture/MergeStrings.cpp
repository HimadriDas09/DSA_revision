#include<iostream>
#include<array>
#include<cstring>
using namespace std;

/* for string working but for character array not working */
char* mergeStrings(char* str1, char* str2) {
    int n1 = strlen(str1), n2 = strlen(str2);
    // int n1 = str1.size(), n2 = str2.size();
    int n3 = n1+n2;
    char* ans = new char[n3];
    // string ans = "";
    // for(int i = 0; i < n1+n2; i++) ans += '*';
    if(n1 == 0 && n2 == 0) {
        return ans;
    }

    int st = 0, end = n1+n2-1;
    int i1 = 0, i2 = 0;

    while(st <= end) {
        if(i1 < n1 && i2 < n2) {
            if(str1[i1] <= str2[i2]) {
                ans[st] = str1[i1];
                ans[end] = str2[i2];
                st++,end--;
            }
            else{
                ans[st] = str2[i2];
                ans[end] = str1[i1];
                st++,end--;
            }
            i1++,i2++;
        }
        else if(i1 < n1) {
            ans[st] = str1[i1];
            st++, i1++;
        }
        else {
            ans[st] = str2[i2];
            st++,i2++;
        }
    }
    // ans[n3-1] = '\0';
    return ans;

}

int main() {
    int n1, n2;
    cout << "enter size of first string : ";
    cin >> n1;
    cout << "enter size of second string : ";
    cin >> n2;
    char* str1 = new char[n1];
    cout << "enter the 1st character array : " << endl;
    for(int i = 0; i < n1; i++) {
        cin >> str1[i];
    }
    char* str2 = new char[n2];
    cout << "enter the 2nd character array : " << endl;
    for(int i = 0; i < n2; i++) {
        cin >> str2[i];
    }
    // string str1, str2;
    // cout << "enter string 1 : ";
    // cin >> str1;
    // cout << "enter string 2 : ";
    // cin >> str2;
    char* ans = mergeStrings(str1, str2);
    for(int i = 0; i < n1+n2; i++) {
        cout << ans[i] << " ";
    }
    // cout << ans << endl;
    cout << endl;
    return 0;
}