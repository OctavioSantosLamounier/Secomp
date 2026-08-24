#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int main () {
    fastio;

    int n;
    double k;
    double sum=0;

    cin >> n >> k;

    for(int e,i=0; i<n; i++){
        cin >> e;
        sum += e;
    }

    sum = ceil(k/sum);
    if(sum == 0) sum = 1;

    cout << sum << endl;
    return 0;
}