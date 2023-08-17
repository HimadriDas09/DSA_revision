//print square of n side with only * along both its diagonals
#include<iostream>
using namespace std;
//approach 2 :for n == 5 : i = 1 -> n and within that j = 1 -> n :  print * where i == j || i*j == 6 else print " "

//appraoch 1
void printStars(int n) {
    //spaces1 > star1 > spaces2 > star2
    for(int i = 0; i < n; i++) {
        int space = i;
        if(i >= n/2) {
            space = n-1-i;
        }
        //we get no of spaces for this i
        while(space > 0) {
            cout << " ";
            space--;
        }
        //print one star
        cout << "*";
        //now print spaces
        space = n-2*(i+1);
        if(i >= n/2) {
            space = n-(2*(n-i));
        }
        while(space > 0) {
            cout << " ";
            space--;
        }
        //print a star
        if(n % 2 == 1 && i == n/2){
            cout << endl;
            continue;
        }
        cout << "*" << endl;
    }
}
int main(){
    int n;
    cout << "enter the value of n" << endl;
    cin >> n;
    printStars(n);
    return 0;
}
