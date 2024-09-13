#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
#define F first
#define S second
using namespace std;
typedef long long ll;

void solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    ll rp = 0;
    for (ll i = 1; i <= x; i++) {
        if (k % i) continue;
        for (ll j = 1; i * j <= k and j <= y; j++) {
            if ((k/i) % j) continue;
            ll l = (k / i) / j;
            if(l > z) continue;
            ll dim[3] = {x, y, z};
            ll ans[3] = {i, j, l};
            sort(dim, dim+3);
            sort(ans, ans+3);
            rp = max(rp, (dim[2] - ans[2] + 1) * (dim[1] - ans[1]+1) * (dim[0] - ans[0]+1));  
        }
    }
    cout << rp << endl;

}

int main() {
    fast_io;
    int tt;
    cin >> tt;
    while(tt--){
        solve();
    }
}