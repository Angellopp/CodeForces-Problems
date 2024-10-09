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
set <int> g[maxn];
int parent[maxn];
int sz[maxn];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    g[v].insert(v);
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        for(auto x : g[b]) {
            g[a].insert(x);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) make_set(i);
    for (int i = 0; i < k; i++) {
        int q, u, v;
        cin >> q >> u >> v; u--;
        if(q == 1) {
            v--;
            union_sets(u, v);

        }
        else {
            u = find_set(u);
            if(g[u].size() < v) {
                cout << -1 << endl;
                continue;
            }
            auto it = g[u].end();
            for(int j = 0; j < v ; j++) {
                it--;
            }
            cout << *it + 1 << endl;        
        }
    }
    
}

int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}