#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

struct pokemon{
    ll vida;
    ll dano;
    string tipo;
};

int vantagem (const string &tipo1, const string &tipo2) {
    if (tipo1 == "AGUA"  && tipo2 == "FOGO" ) return 2;
    if (tipo1 == "FOGO"  && tipo2 == "GRAMA") return 2;
    if (tipo1 == "GRAMA" && tipo2 == "AGUA" ) return 2;
    return 1;
}

int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    // entrada
    queue<pokemon> pkAsh;
    for (int i=0; i<n; i++) {
        ll v, d;
        string t;
        cin >> v >> d >> t;
        pkAsh.push({v, d, t});
    }

    queue<pokemon> pkGary;
    for (int i=0; i<m; i++) {
        ll v, d;
        string t;
        cin >> v >> d >> t;
        pkGary.push({v, d, t});
    }

    // batalha
    while (!pkAsh.empty() && !pkGary.empty()) {
        pokemon &A = pkAsh.front();
        pokemon &G = pkGary.front();
 
        ll danoEmG = A.dano * vantagem(A.tipo, G.tipo); 
        ll danoEmA = G.dano * vantagem(G.tipo, A.tipo); 
 
        ll rodadasAteG = (G.vida + danoEmG - 1) / danoEmG; 
        ll rodadasAteA = (A.vida + danoEmA - 1) / danoEmA; 
 
        ll rodadasLimpas = min(rodadasAteG, rodadasAteA) - 1;
        G.vida -= rodadasLimpas * danoEmG;
        A.vida -= rodadasLimpas * danoEmA;
 
        if (rodadasAteG <= rodadasAteA) {
            pkGary.pop();
            if (pkGary.empty()) { 
                cout << "ASH\n"; 
                break; 
            }

            pokemon &G2 = pkGary.front();
            A.vida -= G2.dano * vantagem(G2.tipo, A.tipo);
 
            if (A.vida <= 0) {
                pkAsh.pop();
                if (pkAsh.empty()) { 
                    cout << "GARY\n"; 
                    break; 
                }
            }
        } 
        else {
            pkAsh.pop();
            if (pkAsh.empty()) { 
                cout << "GARY\n"; 
                break; 
            }
        }
    }

    return 0;
}