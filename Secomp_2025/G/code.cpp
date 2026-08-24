#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int n=0;
    string str;
    cin >> str;

    for(int i=0; i<n; i++){
        if(i%4 == 0 && str[i] != 'A') n++;
        if(i%4 == 1 && str[i] != 'C') n++;
        if(i%4 == 2 && str[i] != 'G') n++;
        if(i%4 == 3 && str[i] != 'T') n++;   
    }

    cout << n << endl;
    return 0;
}