#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
const int INF = 1e9+10;
#define ii pair<int,int>

struct Graph {
    vector<int> adj;
    int dist  =  -1;
};

void BFS(vector<Graph>& graph, int start) {
    queue<int> q;
    q.push(start);
    graph[start].dist = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v: graph[u].adj) 
            if (graph[v].dist == -1) {
                graph[v].dist = graph[u].dist + 1;
                q.push(v);
            }
    }
}


int main() {
    fastio;

    int n,m,k;
    cin >> n >> m >> k;

    vector<int> ve(k);
    for(int &i: ve)
        cin >> i;

    sort(ve.begin(), ve.end());

    vector<Graph> graph(n);
    for (int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;

        u--; v--;
        graph[u].adj.push_back(v);
        graph[v].adj.push_back(u);
    }

    BFS(graph, 0);

    ii dm = {INF, -1};
    for (int i: ve) {
        i--;
        if (graph[i].dist != -1) 
            if (graph[i].dist < dm.first) 
                dm = {graph[i].dist, i};
    }

    if (dm.second == -1) {
        cout << -1 << endl;
        return 0;
    }

    cout << dm.second + 1 << ' ' << dm.first << endl;
    return 0;
}