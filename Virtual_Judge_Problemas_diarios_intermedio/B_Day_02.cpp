#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int n = 2e5;
vector <vector<int>> g(n);
vector <bool> vis(n, 0);
// int n = 0;
long long ans = 0, res = 0;

void dfs(int i) {
    for (auto x : g[i]) {
        if (!vis[x]) {
            ans += 1; res += 1ll * g[x].size();
            vis[x] = 1;
            dfs(x);
        }
    }
}
long long ss = 0;
long long cont() {
    for (int i = 0; i < n; i++) {
        ans = 0; res = 0;
        if(!vis[i]) {
            dfs(i);
            ss += (1ll * ans * (ans - 1) / 2) - res/2;
        }
    }
    return ss;
}

int main() {
    fastio;
    int m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    cout << cont() << "\n";
    
}