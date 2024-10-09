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

const int MOD = 998244353;

void solve() {
    ll g, w, l;
    cin >> g >> w >> l;
    cout << (1ll * ((g - w) % MOD) * ((2ll * (l % MOD) + 1) % MOD)) % MOD << endl;
}

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    for (int i = 1; i <= tt; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
