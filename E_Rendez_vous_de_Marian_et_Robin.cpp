#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const ll INF = 2e15;
const int MAXN = 2e5+5;
int n;

vector<pair<int, int>> adj[MAXN];
vector<ll> d(MAXN);
vector<ll> dc(MAXN);
vector<bool> f(MAXN);

void sp(int s) {
    d.assign(n, INF);
    d[s] = 0;
    set<pair<ll, int>> q;
    q.insert({0ll, s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        q.erase(q.begin());
        if(d[v] == INF or f[v]) continue;
        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i+1 << ": " << d[i] << endl;
    }
}
void spc(int s) {
    dc.assign(n, INF);
    dc[s] = f[s] ? 0 : INF;
    set<pair<ll, int>> q;
    q.insert({dc[0], s});
    while (!q.empty()) {
        ll v = q.begin()->second;
        dd(v);
        q.erase(q.begin());
        // if(dc[v] == INF and !f[v]) continue;
        for (auto edge : adj[v]) {
            int to = edge.first;
            ll len = edge.second;
            // if()
            if (min(d[v] + len, dc[v]+len/2) < dc[to]) {
                q.erase({dc[to], to});
                dc[to] = min(d[v]+len, dc[v] + len/2);
                q.insert({dc[to], to});
            }
            // if (dc[v]+len/2 < dc[to]) {
            //     q.erase({dc[to], to});
            //     dc[to] = dc[v] + len/2;
            //     q.insert({dc[to], to});
            // }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i+1 << ": " << dc[i] << endl;
    }
    
}

void solve() {
    int m , h, xd;
    cin >> n >> m >> h;
    for(int i = 0; i < h; i++) cin >> xd, f[xd-1] = 1;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
    }
    sp(0);
    cout << endl;
    spc(0);
    for(int i = 0; i < n; i++) adj[i].clear();
    f.assign(n, 0);

}


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

