#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define dbg(n) cout << "<[" << #n << "] = " << n << ">" << nn
int mod = 1e9+7;
using namespace std;
const int maxn = 2.5e6 + 10;
int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) { 
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if (__gcd(a, b) == 1) {
            cout << "NO\n";
            continue;
        }
        map <int, bool> v;
        for (int i = 0; i <= 1000; i++) {
            v[i*i] = 1;
        }
        int gcd = __gcd(a, b);

        bool can = 0;
        for (int i = 1; i * i < gcd * gcd; i++) {
            if (v[gcd*gcd - i*i]) {
                int x = i;
                int y = sqrt(gcd*gcd - i*i);
                int k = b / gcd;
                int m = a / gcd;
                if (x * k != y * m) {
                    can = 1;
                    cout << "YES\n";
                    cout << 0 << " " << 0 << nn;
                    cout << x*m << " " << y*m << nn;
                    cout << -y * k << " " << x * k << nn;
                    break;
                }
            }
        }
        if (!can) cout << "NO\n";
    }
    return 0;

}


