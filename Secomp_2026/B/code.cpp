#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int flag1 = 0;
    int flag2 = 1;

    int count1 = 0;
    int count2 = 0;

    string str;
    cin >> str;

    for(int i=0; i<n; i++){
        if ((str[i] - '0') == flag1) 
            count1++;
        
        if ((str[i] - '0') == flag2) 
            count2++;
        
        swap(flag1, flag2);
    }

    int ans = min(count1, count2);
    cout << ans << endl;
    
    return 0;
}