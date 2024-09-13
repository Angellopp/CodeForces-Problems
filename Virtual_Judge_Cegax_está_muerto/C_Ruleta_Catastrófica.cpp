#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie (NULL)
#define dbg(x) cerr << " [ " << #x << " = " << x << " ]\n"
#define endl "\n"
#define F first
#define S second
#define mk make_pair
#define rep(ini, n) for (int i = ini; i < n; i++)
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;

const int N = 1e6 + 5;
const int MOD = 998244353;

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
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = 1ll * fact[i - 1] * i % MOD;
    }
    // cout << "1";
    int bus1 = 174692763;
    int bus2 = 324429416;
    // cin >> bus1 >> bus2;
    int m = 1000000;
    map<pair<int,int>, int> mp;
    // for (int i = 1; i <= m; i++) {
    //     for (int j = i; j <= m; j++) {
    //         mp[{i, j}] = mul_mod(i, inv_mod(j));
    //         if( mul_mod(i, inv_mod(j)) == bus) {cout << "[" << i << ", " << j << "]"; break;}
    //     }
    //     // cout << i << " -> " << mul_mod(i, inv_mod(10)) << endl;
    // } 
    // dbg(mul_mod(1, inv_mod(3)));
    for (int y = 1; y <= m; y++) {
        if (mul_mod(bus1, y) < 1000) {cout << mul_mod(bus1, y) << " -> " << y << "\n"; break;}
    }
    for (int y = 1; y   <= m; y++) {
        if (mul_mod(bus2, y) < 1000) {cout << mul_mod(bus2, y) << " -> " << y << "\n"; break;}
    }
    // set<int> val;
    // for (int i = 0; i < n; i++) {

    // }

    // cout << mul_mod(1, inv_mod(5)) << " " <<  mul_mod(2, inv_mod(5));
}