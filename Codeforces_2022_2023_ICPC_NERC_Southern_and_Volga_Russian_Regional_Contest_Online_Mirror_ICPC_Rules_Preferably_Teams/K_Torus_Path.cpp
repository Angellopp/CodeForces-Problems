#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
ll MOD = 998244353;
using namespace std;

int main() {
    fast_io;
    int tt = 1;
    while (tt--) {
        int n, aux;
        cin >> n;
        ll ans = 0;
        ll mn = 1e9 + 100;
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) {
                cin >> aux;
                ans += aux;
                if (i + j == n-1) 
                    mn = min(mn, 1ll * aux);
            }
        
        cout << ans - mn << nn;
    }
    return 0;
}