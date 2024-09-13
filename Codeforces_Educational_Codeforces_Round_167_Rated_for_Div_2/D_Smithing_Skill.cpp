#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mp make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;

const int N = 1e6+3;

int main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector <int> a(n), b(n), c(m);
    for (int i = 0; i < n; i++) cin >> a[i];     
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> c[i];
    vector <pair<int,int>> p(n), ans(N+60);
    int dif_min = 1e9+6;
    for (int i = 0; i < n; i++) {p[i] = {a[i], b[i] - a[i]}; dif_min = min(dif_min, abs(p[i].S));}
    sort(all(p));
    sort(all(a));
    // sort(all(c));
    pair <int,int> mx = {0,0};
    for (int i = 1; i <= N; i++) {
        int ind = upper_bound(all(a), i) - a.begin() - 1;
        ans[i] = {0, i};
        if(ind != -1) {
            int div = (i - p[ind].F) / abs(p[ind].S) + 1;
            ans[i] = max(mp(mx.F + ans[mx.S+1].F, ans[mx.S+1].S), mp(div + ans[i + p[ind].S*(div)].F, ans[i + p[ind].S*(div)].S));
        }
        mx = max(mx, ans[i]);
    }
    int tope = p.back().F;
    // for (int i = max(1, tope-1000); i < tope; i++) cout << i << ": " << ans[i].F << " " << ans[i].S << endl;
    // for (int i = 1; i < tope; i++) cout << i << ": " << ans[i].F << " " << ans[i].S << endl;
    // cout << "\n================================\n";
    // for (int i = tope; i < tope+50; i++) cout << i << ": " << ans[i].F << " " << ans[i].S << endl;
    ll cc = 0;
    for (auto x : c) {
        if(x < N) {
            cc += 2ll * ans[x].F;
        }
        else {
            int k = (x - a[n-1]) / dif_min + 1;
            // dbg(x);
            // dbg(k);
            // dbg(dif_min);
            // dbg(x + k * dif_min);
            cc += 1ll * ans[x - k * dif_min].F + 2ll * k;
        }
    }
    cout << cc << endl;


}