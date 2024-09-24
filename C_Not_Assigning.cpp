#include <bits/stdc++.h>
#define dd(x) cerr << #x << "= " << x << "." << endl;
using namespace std;

const int MAXN = 1e5+5;

void solve() {
    int n, u, v;
    cin >> n;
    vector<int> g[n+1];
    map<pair<int,int>, int> e;
    vector<int> ans(n-1, 0);
    for (int i = 0; i+1 < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(u > v) swap(u, v);
        e[{u, v}] = i;
    }
    if(n == 2) {
        cout << 2 << endl; return;
    }
    if(n == 3) {
        cout << 2 << " " << 3 << endl; return;
    }
    int cnt1 = 0, cnt2 = 0, ini = 0;
    for (int i = 1; i <= n; i++) {
        if(g[i].size() == 1) {cnt1++, ini = i;}
        if(g[i].size() == 2)  cnt2++;
    }
    if(cnt1 != 2 or cnt2 != n-2) {
        cout << -1 << endl;
        return;
    }
    bool par = 0;
    do {
        int u = ini;
        int v = g[ini][0];
        if(ans[e[{min(u,v), max(u,v)}]] != 0) v = g[ini][1];
        ans[e[{min(u,v), max(u,v)}]] = (par ? 2 : 3) ;
        par ^= 1;
        ini = v;
    }
    while(g[ini].size() != 1);
    for (auto& e : ans) {
        cout << e << " ";
    }
    cout << endl;

}


int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}