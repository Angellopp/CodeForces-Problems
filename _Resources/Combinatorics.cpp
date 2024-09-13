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
    if (k > n) return 0;
    int num = fact[n];
    int den = mul_mod(fact[k], fact[n - k]);
    return mul_mod(num, inv_mod(den));
}


int main() {
    fast_io;
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    }
}