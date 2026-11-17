#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ii pair<int,int> 
#define INF 1e9+10

struct No {
    int l   =  -1;
    int r   =  -1;
    int dif = INF; 

    bool operator<(const No &outher) const {
        if (dif == outher.dif)
            return l   <   outher.l;
        else 
            return dif < outher.dif;
    }
};

int main() {
    fastio;

    int n,k;
    cin >> n >> k;

    vector<ii> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i].first;
        v[i].second = i+1;
    }

    sort(v.begin(), v.end());

    vector<No> answer;

    int l=0, r=1;
    while (l < r) {
        int dist = v[r].first  - v[l].first;
        int dd   = v[r].second - v[l].second + 1;

        if (dist == k) {
            if (dd > 0) 
                answer.push_back({v[l].second, v[r].second, dd});
            l++;
        }
        else if (dist < k) {
            if (r == n-1)
                l++;
            else
                r++;
        }
        else if (dist > k)
            l++;
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << answer[0].l << ' ' << answer[0].r << endl;
    return 0;
}