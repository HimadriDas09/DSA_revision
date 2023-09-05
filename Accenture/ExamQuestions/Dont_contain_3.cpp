#include<iostream>
#include<vector>
using namespace std;

/* return all the nos that contain 3 in their decimal format */
vector<int> dontcontain3(int n) {
    vector<int> ans; 

    for(int i = 1; i <= n; i++) {
        if(i <= 10) {
            if(i == 3) {
                ans.push_back(i);
            }
        } 
        else {
            // check each digit 
            int no = i;
            while(no > 0) {
                if(no % 10 == 3) break;
                no /= 10;
            }
            if(no != 0) {
                // no 3 found : put in ans
                ans.push_back(i);
            }
        }
    }
    return ans;
}

int main()
{
    int n; 
    cout << "enter n" << endl;
    cin >> n;
    vector<int> ans = dontcontain3(n);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout << "total cnt of nos that contain 3 : " << ans.size() << endl; 
    return 0;
}