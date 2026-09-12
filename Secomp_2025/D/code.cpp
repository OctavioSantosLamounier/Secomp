#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<double> a(n), b(n);
    for (int i=0; i<n; i++) {
        int ai, bi;
        cin >> ai >> bi;
        a[i] = ai; b[i] = bi;
    }

    double x = 0.0;
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    for (int it=0; it<100; it++) {
        vector<double> c(n);
        for (int i=0; i<n; i++) 
            c[i] = a[i] - x * b[i];

        nth_element(idx.begin(), idx.begin() + k - 1, idx.end(),
            [&](int i, int j){ return c[i] > c[j]; });

        double sumA=0, sumB=0;
        for (int t=0; t<k; t++) {
            sumA += a[idx[t]];
            sumB += b[idx[t]];
        }

        double newX = sumA / sumB;
        if (fabs(newX - x) < 1e-10) {
            x = newX; 
            break; 
        }
        
        x = newX;
    }

    printf("%.10f\n", x);
    return 0;
}