#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int bit_[200005];
int N;

void update(int i){ // posição 0-indexada
    for (++i; i <= N; i += i & (-i)) bit_[i]++;
}
ll query(int i){ // soma de [0..i], 0-indexado inclusive
    if (i < 0) return 0;
    long long s = 0;
    for (++i; i > 0; i -= i & (-i)) s += bit_[i];
    return s;
}

int main(){
    cin >> N;
    vector<ll> a(N);
    for (auto &x: a) 
        cin >> x;

    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j){ return a[i] > a[j]; });

    ll total = 0;
    int inserted = 0;
    int idx = 0;
    while (idx < N) {
        int j = idx; 

        while (j < N && a[order[j]] == a[order[idx]]) 
            j++;
        // grupo = order[idx..j)
        for (int t=idx; t<j; t++) {
            int pos = order[t];
            ll less = query(pos - 1);
            ll greater = inserted - less;
            total += min(less, greater);
        }
        for (int t=idx; t<j; t++) {
            update(order[t]);
            inserted++;
        }
        idx = j;
    }

    printf("%lld\n", total);
    return 0;
}