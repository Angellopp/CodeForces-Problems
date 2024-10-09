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


const int maxn = 2e5+5; 
vector <pair<int,int>> g[maxn];
ll val[maxn]{};
bool vis[maxn]{};

void dfs(int u) {
    vis[u] = 1;
    for(auto&[v, h] : g[u]) {
        if(vis[v]) continue;
        val[v] = val[u] + 1ll * h;
        dfs(v);
    }
}



void solve() {
    int n, e;
    cin >> n >> e;
    for (int i = 0 ; i < e; i++){
        int u, v, h; cin >> u >> v >> h;
        u--; v--;
        g[u].emplace_back(v, h);
        g[v].emplace_back(u, -h);
    }
    for (int i = 0; i < n; i++) {
        if(vis[i]) continue;
        dfs(i);
    }
    for (int i = 0; i < n; i++) cout << val[i] << " ";
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}