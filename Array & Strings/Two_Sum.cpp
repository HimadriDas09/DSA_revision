#include<bits/stdc++.h>

//most optimal
//TC : O(n), SC : O(n)
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n){

    unordered_map<int,int>mp;

    vector<pair<int, int>> ans;

    for(auto it:arr){

        if(mp[target-it]){

            ans.push_back({target-it,it});
			//bcz we cannot use the same elem twice 
			/*so if duplicate of arr[i] appears then we cannot use 
			target - arr[i] so it, since we've used it for arr[i]*/
            mp[target-it]--;

        }

        else mp[it]++;

    }

    if(ans.size()==0) ans.push_back({-1,-1});
    return ans;
}
