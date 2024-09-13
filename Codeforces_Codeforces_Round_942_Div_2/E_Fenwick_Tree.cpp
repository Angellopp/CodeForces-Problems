#include <bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define nn '\n'
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define readv(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define printv(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << nn
#define fori(ini, n) for(int i = ini; i < n; i++)
#define uu(n) cout << "<[" << #n << "] = " << n << ">" << nn
#define all(n) n.begin(), n.end()
using namespace std;

int lowbit(int k) {
    return (k & -k);
}

const int MOD = 998244353;


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

int main() {
    fastio;
    int tt = 1;
    cin >> tt;
    while (tt--) {
        ll n, k;
        cin >> n >> k;
        vector <ll> v(n);
        readv(v, n);
        for (int i = 1; i <= n; i++) {
            ll mul = 1;
            for (ll j = i + lowbit(i), d = 1; j <= n; j += lowbit(j), d++) {
                mul = (mul * (1ll * (k-1 + d) * inv_mod(d) % MOD)) % MOD;
                v[j-1] = ((v[j-1] - v[i-1] * mul) % MOD + MOD) % MOD;
            }
        }
        printv(v);
    }
    return 0;
}