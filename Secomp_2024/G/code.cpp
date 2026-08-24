#include <bits/stdc++.h>
using namespace std;

int subSetSum (const vector<int> &v, int p){
    vector<bool> dp(p+1, false);

    dp[0] = true;
    int best=0;
    
    for (int num : v)
        for (int i=p; i>=num; --i)
            if (dp[i] || dp[i - num]){
                best = max(best,i);
                dp[i] = true;
            }

    return best;
}


int main(){
    int n,p;
    cin >> n >> p;

    vector<int> v(n);
    for(int &i : v)
        cin >> i;

    int ans = subSetSum(v,p);

    cout << ans << endl;   
    return 0;
}