#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

// Floyd-Warshall entre as 26 letras
void floydWarshall (int dist[26][26]) {
    for (int k=0; k<26; k++)
        for (int i=0; i<26; i++) {
            if (dist[i][k] >= INF) continue;
            for (int j=0; j<26; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
        }
}

void inicializar (int dist[26][26]) {
    for (int i=0; i<26; i++)
        for (int j=0; j<26; j++)
            dist[i][j] = (i==j) ? 0 : INF;
}


int main(){
    fastio;

    int n, m;
    cin >> n >> m;

    int dist[26][26];
    inicializar(dist);

    // entrada
    for (int i=0; i<m; i++){
        char ca, cb;
        cin >> ca >> cb;

        int a = ca - 'a';
        int b = cb - 'a';
        
        dist[a][b] = 1;
        dist[b][a] = 1;
    }

    floydWarshall(dist);
    

    string strIni, strFin;
    cin >> strIni >> strFin;

    // pesquisa
    long long total = 0;
    for (int i=0; i<n; i++) {
        int a = strIni[i] - 'a';
        int b = strFin[i] - 'a';

        if (dist[a][b] >= INF) {
            cout << -1 << endl;
            return 0;
        } 

        total += dist[a][b];
    }

    cout << total << endl;
    return 0;
}