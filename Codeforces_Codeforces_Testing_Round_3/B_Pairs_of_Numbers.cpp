#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fast_io ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define jk(n) cout << "<[" << #n << "] = " << n << ">" << nn
ll MOD = 998244353;
const int INF = 1e9 + 7;
using namespace std;

vector <int> fib;

int f(int n, int m) {
    if (n > m) swap(n, m);
    if (n == 1) return m;
    int q = m / n, r = m % n;
    return q + f(r, n);    
}

int main() {
    fast_io;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n == 1) {cout << 0; return 0;}
        int ans = INF;
        for (int i = 1; i <= n/2; i++) {
            if (__gcd(i, n-i) == 1) {
                ans = min(1 + f(i, n-i), ans);
            }
        }
        cout << ans - 1<< nn;
    }
    return 0;
}