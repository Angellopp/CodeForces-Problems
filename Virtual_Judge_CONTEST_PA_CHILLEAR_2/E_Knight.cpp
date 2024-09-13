#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define ll long long
using namespace std;

const int N = 1e6 + 5;
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
    fastio;
    int n, m;
    cin >> n >> m;
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    }
    if((2*m - n) % 3 or (2*m - n) % 3 or 2*m - n < 0 or 2*n - m < 0) {
        cout << 0 << "\n";
        return 0;
    }
    ll a = (2*m - n)/3;
    ll b = (2*n - m)/3;
    cout << C(a + b, a) << "\n";




}