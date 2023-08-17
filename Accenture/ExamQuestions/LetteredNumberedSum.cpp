#include<iostream>
#include<unordered_map>
using namespace std;

/* Question : A = 1, B = 100,......, G = 1000000 only till G, to the fn a string is passed > String contain UpperCase letters only, Compute the value of the string acc to value of each letter to be added up and return the final sum : sum should lie within integer range, Return 0 if string is NULL */

int LetteredNumberSum(string str) {
    unordered_map<char,int> mp;
    /* A = 65 : ASCII code and goes till 90 */
    int no = 1, sum = 0;
    for(int i = 0; i < 7; i++) {
        char ch = 65 + i;
        mp[ch] = no;
        no *= 10;
    }   
    //now traverse the str and compute sum
    for(int i = 0; i < str.size(); i++) {
        if(mp.find(str[i]) != mp.end()) sum += mp[str[i]];
        else sum += 0; //char other than A...G is computed as 0;
    }
    return sum;
}

int main()
{
    string str;
    cout << "enter the string : ";
    cin >> str;
    if(str.size() == 0) cout << "enter greater sized string" << endl;
    else cout << "ans : " << LetteredNumberSum(str) << endl;
    return 0;
}