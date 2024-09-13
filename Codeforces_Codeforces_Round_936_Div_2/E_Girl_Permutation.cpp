#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)
#define dbg(x) cout << " [ " << #x << " = " << x << " ]\n";
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int fact[N];

int mul_mod(int a, int b) {
    return 1ll * a * b % MOD;
}

int pow_mod(int a, int e) {
    int r = 1;
    while(e) {
        if (e & 1) r = mul_mod(r, a);
        a = mul_mod(a, a);
        e >>= 1;
    }
    return r;
}

int inv_mod(int a) { 
 return pow_mod(a, MOD - 2);
}

int C(int n, int k) {
    int num = fact[n];
    int den = mul_mod(fact[k], fact[n - k]);
    return mul_mod(num, inv_mod(den));
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> a(m1), b(m2);
    for (int &e : a) cin >> e;
    for (int &e : b) cin >> e;
    
    
    if (a[0] != 1 or b[m2-1] != n or a[m1-1] != b[0]) {
        cout << "0\n";
        return;
    }
    
    int j = a.back();
    
    // a = pref   b = suf
    int ans = C(n - 1, j - 1);
    for (int i = 1; i < m1; i++) {
        int r = C(a[i] - 2, a[i] - a[i - 1] - 1);
        ans = mul_mod(ans, r);
        ans = mul_mod(ans, fact[a[i] - a[i - 1] - 1]); 
    }
    for (int i = 0; i < m2; i++) {
        b[i] = n + 1 - b[i];
    }
    reverse(b.begin(), b.end());
    for (int i = 1; i < m2; i++) {
        int r = C(b[i] - 2, b[i] - b[i - 1] - 1);
        ans = mul_mod(ans, r);
        ans = mul_mod(ans, fact[b[i] - b[i - 1] - 1]); 
    }
    cout << ans << "\n";
}

int main() {
    fast_io;
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
        
    }

    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}