
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define dbg(x) cerr << #x << " = " << x << endl
#define raya cerr << string(20, '=') << endl
#define pv(x) cerr << #x << ": "; for (auto e : x) cerr << e << " "; cerr << endl
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define ff first
#define ss second

typedef long long ll;

const int N = 1e4+5;
const int INF = 1e9;

void solve() {
    ll n, q;
    cin >> n >> q;
    vector <int> v(n);
    vector <ll> prev(2*n+1, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    prev[0] = 0;
    for (int i = 1; i <= n; i++) 
        prev[i] = prev[i-1] + 1ll * v[i-1];
    for (int i = 1; i <= n; i++) 
        prev[n+i] = prev[n+i-1] + 1ll * v[i-1];
    
    ll l, r, bl, br;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        l--; r--;
        ll ans = 0;
        bl = l/n, br = r/n;
        ans += (br - bl) * sum;
        ans += prev[br + r % n + 1] - prev[br];
        ans -= prev[bl + l % n] - prev[bl];
        cout << ans << endl;
    }
}

int main() {
    fastio;
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}
