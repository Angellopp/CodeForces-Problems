#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define cp(x) cerr << " [ " << #x << " = (" << x.F << ", " << x.S << ") ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define all(x) x.begin(), x.end()
#define ll long long 
#define clz(x) __builtin_clz(x) 
#define ctz(x) __builtin_ctz(x) 

using namespace std;

int maxn = 500+4;
void solve() {
    int n, aux;
    cin >> n;
    map <int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        m[aux-i]++;
    }
    ll ans = 0;
    for(auto x : m) {
        ans += x.S * 1ll * (x.S-1) / 2; 
    }
    cout << ans << endl;
}

int main() {
    fastio;
    int q;
    cin >> q;
    while(q--) {
        solve();
    }
    return 0;
}
