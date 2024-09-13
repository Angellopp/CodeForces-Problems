#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define F first
#define S second
using namespace std;
typedef long long ll;
void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int l, xd; cin >> l;
        for (int j = 0; j < l; j++) {
            cin >> xd;
            v[i].emplace_back(xd);
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sort(all(v[i]));
        int mex = 0;
        for (int j = 0; j < v[i].size(); j++) {
            if(v[i][j] > mex) break;
            else if(v[i][j] == mex) mex++;
        }
        int mex2 = mex+1;
        for (int j = 0; j < v[i].size(); j++) {
            if(v[i][j] > mex2) break;
            else if(v[i][j] == mex2) mex2++;
        }
        ans = max(ans, 1ll * mex2);
    }
    // dbg(ans);
    // dbg(m);
    ll cnt = min(ans, 1ll*m);
    ll r = 1ll * (ans) * (cnt+1) + 1ll * m * (m+1) / 2 - cnt * (cnt+1) / 2;
    cout << r << endl;
}

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while(tt--){
        solve();
    }
}