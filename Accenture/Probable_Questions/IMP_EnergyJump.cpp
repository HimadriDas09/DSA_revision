#include<iostream>
using namespace std;

int f(int* E, int* J, int n, int DE) {
    int hrs = 0, ind = 0, cur_en = 0; // cur_en is current energy

    while(ind <= n-1 || cur_en <= DE) {
        hrs++;
        cur_en += E[ind];

        if(ind < n-1 && cur_en >= J[ind]) {
            cur_en -= J[ind]; // use accumulated energy
            ind++; // jump to next city
        }

        // if accumulated devils energy
        if(ind == n-1 && cur_en >= DE) break;
    }
    return hrs;
}

int main()
{
    int n;
    cout << "enter n : " << endl;
    cin >> n;
    int DE;
    cout << "enter devil energy: " << endl; 
    cin >> DE;
    int* E = new int[n];
    int* J = new int[n-1];

    cout << "enter Cities : " << endl;
    for(int i = 0; i < n; i++) cin >> E[i];

    cout << "enter threshold energies :  " << endl;
    for(int i = 0; i < n-1; i++) cin >> J[i];

    cout <<  f(E, J, n, DE) << endl;
    return 0;
}