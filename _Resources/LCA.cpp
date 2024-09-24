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


const int maxn = 1e5;
const int root = 1;

vector <int> g[maxn];
vector <int> fa(maxn);
vector <pair<int,int>> es(maxn);
vector <vector<int>> ances(maxn, vector<int>(20+5));

int n;
int t = 1;

void generar_ances(int u) {
    ances[u][0] = u;
    ances[u][1] = fa[u];
    for (int k = 2; k <= 20; k++) {
        ances[u][k] = ances[ances[u][k-1]][k-1];
    }
}

void dfs(int u, int p) {
    es[u].F = t++;
    generar_ances(u);
    for (int v : g[u]) {
        if(v != p) {
            fa[v] = u;
            dfs(v,u);
        }
    }
    es[u].S = t++;
}

bool is_anc(int u, int v) {
    return (es[u].F <= es[v].F and es[u].S >= es[v].S);
}

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    dbg(is_anc(u, v));
    dbg(is_anc(v, u));
    for (int r = 20; r >= 0; r--) {
        if (!is_anc(ances[u][r], v)) u = ances[u][r];
    }
    return fa[u];
} 



int main() {
    fastio;
    int q, u, v;
    cin >> n >> q;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    fa[root] = root;
    dfs(root, root);
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " -> ";
    //     for (int j = 0; j <= 10; j++) {
    //         cout << ances[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " -> " << es[i].F << " " << es[i].S << "\n";
    // }
    cout << "\n" << LCA(15, 14);
}