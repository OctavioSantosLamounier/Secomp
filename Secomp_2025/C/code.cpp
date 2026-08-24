#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int a,b;

    cin >> a >> b;
    vector<int> v(a,0);

    while(b--){
        int c; 
        string str;
        cin >> str >> c;

        if(str == "CHEGADA")
            v[c-1] = 1;
        else if(str == "SAIDA")
            v[c-1] = 0;
    }

    int res=0;
    for(int i=0; i<a; i++)
        res = res + v[i];
    
    cout << res << endl;
    return 0;
}