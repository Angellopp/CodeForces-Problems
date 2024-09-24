#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;
const int MAX = 1e5+5;

const int INF = 1000000000;
// vector<vector<pair<int, int>>> adj;
vector <pair<int,int>> adj[MAX];
vector<ll> d(MAXN);
// vector<ll> p(MAXN);

void dijkstra(int s) {
    int n = adj.size();
    d.assign(n, INF);
    // p.assign(n, -1);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                // p[to] = v;
                q.insert({d[to], to});
            }
        }
    }
}

int main() {
;
}