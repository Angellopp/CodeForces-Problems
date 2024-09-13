#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)


using namespace std;

const int maxn = 2e5+10;
vector <int> v(maxn);
vector <int> g[maxn];

int dfs(int u) {
    if(g[u].empty()) return v[u];
    int min_hijos = 1e9;
    for (int v : g[u]) {
        min_hijos = min(dfs(v), min_hijos);
    }
    if(u == 1) return min_hijos;
    if(v[u] >= min_hijos) return min_hijos;
    else return (v[u] + min_hijos)/2;
}

void solve() {
    int n, p;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 2; i <= n; i++) {
        cin >> p;
        g[p].emplace_back(i);
    }
    cout << v[1] + dfs(1) << endl;
    for (int i = 1; i <= n; i++) g[i].clear();  
}

int main() {
    fastio;
    int q;
    cout << fixed << setprecision(10);
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
