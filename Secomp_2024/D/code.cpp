#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

typedef pair<int,int> ii;
#define f first
#define s second

int main() {
    fastio;

    int h,w,n;
    cin >> h >> w >> n;

    vector<ii> vii;

    while(n--){
        int x,y,r;
        cin >> x >> y >> r;

        int li = max(0, y-r); // limite inferior do macaco
        int ls = min(h, y+r); // limite superior do macaco
    
        vii.push_back({li,ls});
    }

    sort(vii.begin(), vii.end());

    int inicio = 0;
    for(ii p : vii){
        if(p.f > inicio)
            break;

        inicio = max(inicio, p.s);
    }

    bool ans = inicio >= h;

    cout << (ans ? "sim" : "nao") << endl;
    return 0;
}