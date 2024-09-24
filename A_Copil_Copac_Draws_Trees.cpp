#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int mx = 2e5+5;
vector<pair<int,int>> g[mx];
vector<int> dp(mx), id(mx);

void dfs(int u = 1) {
    for(auto v : g[u]) {
        if(dp[v.ff]) continue;
        dp[v.ff] = dp[u] + (v.ss < id[u]);
        id[v.ff] = v.ss;
        dfs(v.ff);
    }
}

void solve() {
    int n, u, v;
    cin >> n;
    dp[1] = 1, id[1] = 0;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    dfs();
    int ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans << endl;

    for(int i = 1; i <= n; i++) g[i].clear(), dp[i] = 0;

}


int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

