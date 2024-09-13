#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;


const int maxn = 1e5+5;
const int LOGN = 20;
const int root = 1;

vector <int> g[maxn];
int h[maxn];
pair<int,int> es[maxn];
int ances[maxn][LOGN];

int n;
int t = 1;

void generar_ances(int u, int p) {
    ances[u][0] = p;
    for (int k = 1; k < LOGN; k++) {
        ances[u][k] = ances[ances[u][k-1]][k-1];
    }
}

void dfs(int u, int p) {
    es[u].F = t++;
    generar_ances(u, p);
    h[u] = h[p] + 1;
    for (int v : g[u])
        if(v != p) dfs(v,u);
    
    es[u].S = t++;
}

bool is_anc(int u, int v) {
    return (es[u].F <= es[v].F and es[u].S >= es[v].S);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int r = LOGN-1; r >= 0; r--) {
        if (!is_anc(ances[u][r], v)) u = ances[u][r];
    }
    return ances[u][0];
} 

int dis(int u, int v) {
    return h[u] + h[v] - 2 * h[LCA(u, v)]; 
}

int main() {
    fastio;
    int q, u, v;
    cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    
    dfs(root, root);
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int r1 = (dis(a, b) + dis(c, d) - dis(a, c) - dis(b, d)) / 2;
        int r2 = (dis(a, b) + dis(c, d) - dis(b, c) - dis(a, d)) / 2;
        int ans = max(r1, r2);
        if (ans < 0) cout << "0\n";
        else cout << ans + 1 << "\n";
    }
}