#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    int n;
    cin >> n;

    set<int> s = {2, 3, 5, 7, 23, 37, 53, 73, 373};

    cout << (s.count(n) ? "sim" : "nao") << endl;
    return 0;
}