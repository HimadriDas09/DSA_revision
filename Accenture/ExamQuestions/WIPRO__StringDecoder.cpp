#include<iostream>
using namespace std;
/* QUESTION: A = 1, B = 11, C = 111,.....till Z */
/* now a resultant string will be given and between each sequence of 1s, a 0 is given for separation of each letter : string starts from 1 and ends at 0 
return the letter output of the string of 1s and 0s */

string stringDecoder(string input) {
    int st = 0, end = 0;
    string ans = "";
    while(st <= input.size() && end <= input.size()) {
        if(input[end] == '0') {
            //prev char is a 1 && from st to end-1 is a string we need to decode
            int len = end-1-st+1;
            char ch = 'A' + len-1;
            ans += ch;
            st = end+1;//next char is 1 i.e start of a new string
        }
        end++;
    }
    return ans;
}

int main()
{
    string str;
    cout << "enter the string : ";
    cin >> str;
    cout << "decoded string : " << stringDecoder(str) << endl;
    return 0;
}
