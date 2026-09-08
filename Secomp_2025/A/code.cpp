#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main() {
    fastio;

    int n;
    cin >> n;

    vector<pair<int,int>> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }

    stable_sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.first < b.first;
    });

    for (int i=0; i<n; i++)
        cout << v[i].second << ' ';
    
    cout << endl;
    return 0;
}