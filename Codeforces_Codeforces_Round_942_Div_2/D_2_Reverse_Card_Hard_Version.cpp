#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

int main() {
    fast_io;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        ll m, n;
        cin >> n >> m;
        ll ans = 0;
        for (ll i = 1; i*i <= n; i++) {
            for (ll j = 1; j*j <= m; j++) {
                if (__gcd(i, j) == 1) {
                    ans += min(n/((i+j)*i), m/((i+j)*j));
                }
            }
        }
        cout << ans << nn;
        
    }
    return 0;
}