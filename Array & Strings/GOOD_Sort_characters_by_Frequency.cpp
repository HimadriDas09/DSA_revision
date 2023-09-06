/* put characters in a mp, from mp put in a vector<pair<char,int>> then
sort the vector according to whosevers int value is greater */
class Solution {
private: 
    static bool cmp(pair<char,int> &a, pair<char,int> &b) {
        return a.second > b.second; /* a then b if a's char cnt is greater than
        b => so sorting in dec order of char cnt */
    }
public:
    string frequencySort(string s) {
        int n = s.size();
        // SC:O(n)
        unordered_map<char,int> mp; // char : cnt
        // TC: O(n)
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        vector<pair<char,int>> v;
        for(auto it:mp) v.push_back(it);
        // TC: O(nlogn)
        sort(v.begin(), v.end(), cmp);

        // now traverse the vector sorted in dec order acc to char cnt
        string ans = "";
        // TC: O(n)
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].second; j++) {
                ans += v[i].first;
            }
        }
        return ans;
    }
};