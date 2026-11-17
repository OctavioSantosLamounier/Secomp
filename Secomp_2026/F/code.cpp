#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio;

    int a,b,c;
    cin >> a >> b >> c;
    vector<int> v(a,0);

    for(int &i: v)
        cin >> i;

    int acc = 0;
    for(int i=b-1; i<c; i++)
        acc += v[i];

    cout << acc << endl;

    return 0;
}