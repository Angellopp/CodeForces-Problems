#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

const int MAXN = 1e5+5;

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll g;
    cin >> g;
    vector<ll> dp;
    vector <int> v(g);
    for (int i = 0; i < g; i++) cin >> v[i];
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            dp.emplace_back((min(n-k, i) - max(0ll, i-k+1) + 1) * (min(m-k, j) - max(0ll, j-k+1) + 1));
        }
        // cout << endl;
    }
    sort(rall(v));
    sort(rall(dp));
    ll ans = 0;
    for (int i = 0; i < g; i++) {
        ans += dp[i] * 1ll * v[i];
    }
    cout << ans << endl;
}


int main() {
    fastio;
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
}

