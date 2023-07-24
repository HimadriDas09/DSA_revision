#include <bits/stdc++.h> 
#include<iostream>
using namespace std;

//fmax() returns double/float/long values
double maximizeNum(int i, int extra, vector<vector<int>> &bulbs, int &n, vector<vector<int>> temp) {
    //bc
    if(extra == 0) {
        //sum up all the num ratios and return
        double ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (double) temp[i][0]/temp[i][1];
            cout << "temp value in " << i << " th itern " << temp[i][0] << " " << temp[i][1] << endl;
            cout << "current ans value in " << i << " th itern " << ans << endl;
        }
        cout << "base case calculated ans " << ans << endl;
        cout << "****************" << endl;
        return ans;
    }
    if(i < 0) {
        //extra != 0 && reached < 0 => reject this case > return -infinity
        //since everything is 1 so ratio cannot be 0
        return 0;
    }

    //sc
    //not assign
    double notAssign = maximizeNum(i-1, extra, bulbs, n, temp);
    
    //assign > we're assigning one at a time
    //assign > we can assign to all > && we can assign to BULBS[i] multiple times

    //inc working & total each by 1
    temp[i][0]++;
    temp[i][1]++;
    double assign = maximizeNum(i, extra-1, bulbs, n, temp);

    /*both returns max ratio of num > whichever is max return it*/
    return fmax(notAssign, assign);
}
double maxAverageWorkingRatio(vector<vector<int>>& bulbs, int n, int extra) {
    // Write your code here
    vector<vector<int>> temp = bulbs;

    double maxNumSum = maximizeNum(n-1, extra, bulbs, n, temp);
    cout << "max Num Sum returned in fn " << maxNumSum << endl;
    double ans = (double) maxNumSum/n;
    cout << "ans in fn" << ans << endl;
    return ans;
}

int main(){
    int n = 3, extra = 2;
    vector<vector<int>> bulbs = {{2,3}, {3,5}, {2,2}};
    double returnedAns = maxAverageWorkingRatio(bulbs, n, extra);
    cout << "ans in main after div by 3" << returnedAns << endl;
    return 0;
}