#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
using namespace std;

const int INF = 1e9 + 7;
const int maxn = 1e5 + 10;

vector <int> g[maxn];
bool vis[maxn];
int nhijos[maxn];
int k;

void clean(int n) {
    fill(vis+1, vis+n+1, false);
    fill(g+1, g+n+1, vector <int> ());
}

void dfs(int i) {
    vis[i] = true;
    int ans = 0, ind_ans = 0, kaux = k;
    for (int v: g[i]) {
        if (vis[v]) continue;
        // int aux = max(ans, min(nhijos[v], nhijos[i] - nhijos[v]));
        // if (aux != ans) ind_ans = aux;
        if (ans < min(nhijos[v], nhijos[i] - nhijos[v])) {
            ans = min(nhijos[v], nhijos[i] - nhijos[v]);
            ind_ans = i;
        }


        // dfs(v);
    }
}
int dfsnh(int i) {
    vis[i] = true;
    nhijos[i] = 1;
    for (int v: g[i]) {
        if (vis[v]) continue;
        nhijos[i] += dfsnh(v);
    }
    return nhijos[i];
}



int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n >> k;

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        n = dfsnh(1);

        for (int i = 1; i <= n; i++) {
            cout << i << ": ";
            for (int j : g[i]) cout << j << " ";
            cout << nn;
            cout << "numero de hijos de " << i << ": \n";
            cout << nhijos[i] << nn;
        
        }
        clean(n);

    }
    return 0;
}