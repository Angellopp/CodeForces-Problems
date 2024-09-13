#include <bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;
ll sz = 0;
int ans = 0;
vector <ll> g(40+3, 0);
vector <pair<int,ll>> gg;
vector <int> vis;
ll visb = 0;

void backtracking(int i, int cnt=0) {
    if (i == sz) {
        ans = max(ans, cnt);
        return;
    }
    if (vis[sz-1-gg[i].first] == 1) {
    // if (((visb>>(gg[i].first)) & 1ll) == 1ll) {
        return backtracking(i+1, cnt);
    }
    if(__builtin_popcountll(gg[i].second) == 1) {
        vis[sz-1-gg[i].first] = 1;
        // visb |= (1ll<<(gg[i].first));
        int aux = 63-__builtin_clzll(gg[i].second);
        vis[sz-1-aux] = 1;
        // visb |= (1ll<<aux);
        return backtracking(i+1, cnt+1);
    }

    vector <int> aux = vis;
    // ll aux = visb;
    
    vis[sz-1-gg[i].first] = 1;
    // visb |= (1ll<<(gg[i].first));
    for (ll j = 0; j < sz; j++) {
        if ((((gg[i].second)>>j) & 1) and vis[sz-1-j] == 0) {vis[sz-1-j] = 1;}
        // if ((((gg[i].second)>>j) & 1ll) and ((visb>>j) & 1ll == 0)) {visb |= (1ll<<j);}
    }

    backtracking(i+1, cnt+1);
    vis = aux;
    // visb = aux;
    backtracking(i+1, cnt);
    return;
}
void imprimir() {
    for (int i = 0; i < sz; i++) {
        cout << "-> " << gg[i].first << " " << gg[i].second << "\n";
    }
}
map<string, ll> mm;

int main() {
    fast_io;
    int n, m;
    cin >> n >> m;
    ++n;
    set<string> mp;
    int c;
    while (n--) {
        if (n == 0) c = 1;
        else cin >> c;
        if (c == 2) {
            string s;
            cin >> s;
            mp.insert(s);
        }
        else if (!mp.empty()){
            vector <string> v;
            for (string s : mp) {
                v.emplace_back(s);
                if(!mm.count(s)) mm[s] = sz++;
            }
            for (int i = 0; i < (int)v.size(); i++) {
                for (int j = i+1; j <(int)v.size(); j++) {
                    g[mm[v[i]]] |= (1LL<<mm[v[j]]);
                    g[mm[v[j]]] |= (1LL<<mm[v[i]]);
                }
            }
            mp.clear();
        }
    }
    int sumaux = 0, xx2 = 0;
    for (int i = 0; i < sz; i++) {
        if (g[i] == 0) sumaux++;
        else if (g[i] == 1) {gg.emplace_back(i, g[i]); xx2++; }
    }
    for (int i = 0; i < sz; i++) {
        if (g[i] > 1) gg.emplace_back(i, g[i]); 
    }
    sz = gg.size();

    // imprimir();
    sort(gg.begin() + xx2, gg.end(), [](pair<int,ll> a, pair<int,ll> b) {
        return __builtin_popcountll(a.second) > __builtin_popcountll(b.second);
    });
    // imprimir();
    vis.resize(sz, 0);
    backtracking(0);

    cout << ans + sumaux << "\n";
    return 0;
}
