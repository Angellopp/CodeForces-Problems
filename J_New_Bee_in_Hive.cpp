#include <bits/stdc++.h>
#define endl '\n'
#define dd(x) cerr << #x << "= " << x << "." << endl;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
using namespace std;

// const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

// int fact[N];

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
// int inv_mod(int a) { 
//     return pow_mod(a, MOD - 2);
// }
// int C(int n, int k) {
//     if (k > n) return 0;
//     int num = fact[n];
//     int den = mul_mod(fact[k], fact[n - k]);
//     return mul_mod(num, inv_mod(den));
// }


void solve() {
    int n; cin >> n;
    int ans = 1;
    for (int i = 1 ; i <= n; i++) {
        ans = mul_mod(mul_mod(2, ans), i);
    }
    for (int i = n+1 ; i > 1; i--) {
        ans = mul_mod(mul_mod(2, ans), i-1);
    }
    cout << ans << endl;
}


int main() {
    fastio;
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}

