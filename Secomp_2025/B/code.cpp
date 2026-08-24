#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int n;
    string str;
    bool res = true;

    cin >> str >> n;

    for(int i=0; i<(int)str.size(); i++)
        if(str[i] >= n+'0')
            res = false;
    
    cout << (res ? "SIM" : "NAO") << endl;
    return 0;
}