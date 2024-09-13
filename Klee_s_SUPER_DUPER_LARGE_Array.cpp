
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

ll sum(ll x) {return x * (x+1) / 2;}

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1e18;
    ll l = k, r = k + n - 1;
    ll t = sum(r) - sum(l-1);
    // ll mid = (l + r + 1) / 2 - 1;
    ll top = t/2 + sum(l-1);
    ll mid = sqrt(2*top);
    while(sum(mid)> top) mid--;

    ans = min(ans, abs(sum(r) - 2 * sum(mid) + sum(l-1)));
    mid++;
    ans = min(ans, abs(sum(r) - 2 * sum(mid) + sum(l-1)));
    // int cnt = 0;
    // for (mid; cnt <= 1e7; cnt++, mid++){
    // }
    cout << ans << endl;
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
