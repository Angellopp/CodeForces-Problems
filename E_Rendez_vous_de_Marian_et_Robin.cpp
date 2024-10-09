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
const ll INF = 1e18;
const int MAXN = 2e5+5;
int n;

vector<pair<int, int>> adj[MAXN];
vector<bool> f(MAXN);

void sp(int s, vector<vector<ll>> &d) {
    auto cmp = [&](auto &a, auto &b){return make_pair(d[a.first][a.second],a) < make_pair(d[b.first][b.second],b);};
    set<pair<int,int>,decltype(cmp)> q(cmp);
    d[s][0] = 0;
    q.insert({s, 0});
    while (!q.empty()) {
        auto [v, h] = *q.begin();
        q.erase(q.begin());
        bool horse = (h or f[v]);
        for (auto &[to, len] : adj[v]) {
            ll dist = horse ? len / 2 : len;
            if (d[v][h] + dist < d[to][horse]) {
                q.erase({to, horse});
                d[to][horse] = d[v][h] + dist;
                q.insert({to, horse});
            }
        }
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
    vector<vector<ll>> d1(n, vector<ll>(2,INF)), d2(n, vector<ll>(2,INF));
    sp(0, d1);
    sp(n-1, d2);
    ll ans = INF;
    for(int i = 0; i < n; i++) { 
        ans = min(ans, max(min(d1[i][0], d1[i][1]), min(d2[i][0], d2[i][1])));
    }
    cout << (ans == INF ? -1 : ans) << endl;
    for(int i = 0; i < n; i++) adj[i].clear(), f[i] = 0;
}


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

