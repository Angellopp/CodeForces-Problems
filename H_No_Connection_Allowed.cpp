#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ddl cerr << string(20, '=') << endl;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
const int MOD = 1e9+7; 
const double EPS = 1E-9;


vector<int> g[100+5];
vector<int> dis(100+5, 0);

int dfs(int u) {
    if(dis[u]) return dis[u];
    if(g[u].size() == 0) {
        return dis[u] = 1; 
    }
    int mn = 0;
    for(auto x : g[u]) {
        mn = max(mn, dfs(x)); 
    }
    return (dis[u] = 1 + mn);
}

bool f(int a, int b, int c, int d, int x) {
    bool b1 = 0;
    if(a - x >= 0) {
        if(c - x >= 0) {
            b1 = (b * (c - x) < d * (a - x));
        }
        else b1 = 1;
    }
    else {
        if(c - x >= 0) b1 = 0;
        else {
            b1 = (b * (x - c) > d * (x - a));
        }
    }
    return b1;
    // retorna 1 si xa < xb
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    vector <pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].ff >> v[i].ss;   
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == j) continue;
            ll a = v[i].ff;
            ll b = v[i].ss;
            ll c = v[j].ff;
            ll d = v[j].ss;
            bool b1 = f(a, b, c, d, x);
            bool b2 = f(c, d, a, b, y);
            if(b1 and b2) {
                g[i].emplace_back(j);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        dfs(i);
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, dis[i]);
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int tt = 1;
    for (int i = 1; i <= tt; i++) {
        solve();
    }
}
