#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    string str;
    cin >> str; 

    if (str == "H2") 
        str = "O";
    if (str == "HO")    
        str = "2";
    if (str == "2O")      
        str = "H";

    cout << str << endl;
    return 0;
}