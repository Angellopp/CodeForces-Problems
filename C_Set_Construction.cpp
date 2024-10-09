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

const int maxn = 1e2+5;
bool vis[maxn]{};
int acc[maxn]{};
vector<int> g[maxn];

void dfs(int u, vector<vector<bool>>& ans) {
    if(vis[u]) return;
    vis[u] = 1;
    ans[u][u] = 1;
    acc[u]++;
    for (auto& v : g[u]) {
        ans[v][u] = 1;
        acc[v]++;
        dfs(v, ans);
    }
}

void solve() {
    int n; cin >> n;
    vector<vector<bool>> ans(n+1, vector<bool> (n+1));

    string xd;
    for (int i = 0; i < n; i++) {
        cin >> xd;
        for (int j = 0; j < n; j++) {
            if (xd[j] == '1') {
                g[i+1].push_back(j+1);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) dfs(i, ans);
    
    for (int i = 1; i <= n; i++) {
        cout << acc[i] << " ";
        for (int j = 1; j <= n; j++) {
            if(ans[i][j]) cout << j << " ";
        }
        cout << endl;
    }

    for (int i = 0; i <= n; i++) {vis[i] = 0, acc[i] = 0; g[i].clear();}




    
}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}