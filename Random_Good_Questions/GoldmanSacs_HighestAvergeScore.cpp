#include<bits/stdc++.h>
#include<iostream>
using namespace std;
/*
Given a 2-D String array of student-marks find the student with the highest average and output his average score. If the average is in decimals, floor it down to the nearest integer.

Example 1:

Input:  [{"Bob","87"}, {"Mike", "35"},{"Bob", "52"}, {"Jason","35"}, {"Mike", "55"}, {"Jessica", "99"}]
Output: 99
Explanation: Since Jessica's average is greater than Bob's, Mike's and Jason's average.

*/

/*since when we traverse the vector of strings > we should know if some name has appeared before or not > if yes > then update the sum marks and count> could use 
maps > Name : <totScore, cnt> 
*/
//TC : O(n) [avg traveral]+ O(nlogn) [searching] + O(n) [map traversal]
//SC : O(n)
pair<string,int> highestAverageScore(vector<vector<string>> &avg) {
    int n = avg.size();
    unordered_map<string, pair<int,int>> mp; /* if same name appears twice 
    we add up new marks with prev and update the count*/
    for(int i = 0; i < n; i++) {
        string name = avg[i][0];
        string marks = avg[i][1];

        if(mp.count(name) > 0) {
            //fetch it's marks and update it
            mp[name].first += stoi(marks);
        }
        else {
            //just key the name : marks
            mp[name].first = stoi(marks);
        }
        //update cnt
        mp[name].second++;
    } 
    //now traverse the map and calculate avg
    int maxAvg = -1e9;
    string name = "";
    for(const auto it : mp) {
        int avg = it.second.first/ it.second.second;
        if(avg > maxAvg) {
            maxAvg = avg;
            name = it.first;
        }
    }
    return {name, maxAvg};
}

int main() {
    vector<vector<string>> avg =  {{"Bob","87"}, {"Mike", "35"},{"Bob", "52"}, {"Jason","35"}, {"Mike", "55"}, {"Jessica", "69"}, {"Mike", "85"}, {"Bob", "100"}};

    pair<string,int> ans = highestAverageScore(avg);

    cout << "max average marks is : " << ans.second << " and name is : " << ans.first << endl;
}